# Required Problem set 9 by Luis Artavia - finance
# draft processed on: October 08, 2023, October 12, 2023, October 15, 2023 and October 16, 2023
# submitted for grade on: October 17, 2023

import csv
import datetime
import pytz
import requests
import subprocess
import urllib
import uuid

from flask import redirect, render_template, session
from functools import wraps

# NEW import declarations
# from json import loads

""" ORIGINAL HELPER FUNCTIONS """


def apology(message, code=400):
    """Render message as an apology to user."""

    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [
            ("-", "--"),
            (" ", "-"),
            ("_", "__"),
            ("?", "~q"),
            ("%", "~p"),
            ("#", "~h"),
            ("/", "~s"),
            ('"', "''"),
        ]:
            s = s.replace(old, new)
        return s

    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    http://flask.pocoo.org/docs/0.12/patterns/viewdecorators/
    """

    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)

    return decorated_function


def lookup(symbol):
    """Look up quote for symbol."""

    # Prepare API request
    symbol = symbol.upper()
    end = datetime.datetime.now(pytz.timezone("US/Eastern"))
    start = end - datetime.timedelta(days=7)

    # Yahoo Finance API
    url = (
        f"https://query1.finance.yahoo.com/v7/finance/download/{urllib.parse.quote_plus(symbol)}"
        f"?period1={int(start.timestamp())}"
        f"&period2={int(end.timestamp())}"
        f"&interval=1d&events=history&includeAdjustedClose=true"
    )

    # Query API
    try:
        response = requests.get(
            url,
            cookies={"session": str(uuid.uuid4())},
            headers={"User-Agent": "python-requests", "Accept": "*/*"},
        )
        response.raise_for_status()

        # response_ <Response [200]>
        # print(f"\nDEV ONLY ~ response_ {response}")

        # CSV header: Date,Open,High,Low,Close,Adj Close,Volume
        quotes = list(csv.DictReader(response.content.decode("utf-8").splitlines()))

        # [{'Date': '2023-10-02', 'Open': '140.039993', 'High': '141.449997', 'Low': '139.860001', 'Close': '140.800003', 'Adj Close': '140.800003', 'Volume': '3275300'}, ...]

        # print(f"\nDEV ONLY ~ quotes {quotes}")

        quotes.reverse()

        price = round(float(quotes[0]["Adj Close"]), 2)
        return {
            # wotdahell ?!?!?! ... symbol is regurgitated TWICE
            "name": symbol,
            "price": price,
            "symbol": symbol,
        }
    except (requests.RequestException, ValueError, KeyError, IndexError):
        return None


def usd(value):
    """Format value as USD."""
    return f"${value:,.2f}"


""" NEW CUSTOM HELPER FUNCTIONS """


def return_shares(dict):
    num_shares = dict["net_shares"]
    return num_shares


def return_symbols(dict):
    ticker_symbol = dict["symbol"]
    return ticker_symbol


def return_share_price(dict):
    share_price = lookup(dict["symbol"])["price"]
    return share_price


def return_value(dict):
    num_shares = dict["net_shares"]
    share_price = lookup(dict["symbol"])["price"]
    value_of_shares = num_shares * share_price
    value_of_shares = round(value_of_shares, 2)
    return value_of_shares


""" NEW DATE/TIME FILTER """

# convert string to datetime object, then, format back to format-specific string
# ATTRIBUTION - https://bobbyhadz.com/blog/python-attributeerror-str-object-has-no-attribute-strftime


def datetime_format(value, format="%B %d, %Y, %I:%M%p"):
    datetime_obj = datetime.datetime.strptime(value, "%Y-%m-%d %H:%M:%S")
    datestring = datetime_obj.strftime(format)  # November 24, 2024, 09:30AM
    return datestring


# fin.
