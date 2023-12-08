# Required Problem set 9 by Luis Artavia - finance
# draft processed on: October 08, 2023 through October 12, 2023; October 14, 2023 through October 17, 2023
# submitted for grade on: October 17, 2023

# sqlite3 finance.db '.dump' > dump.sql
# sqlite3 finance.db

import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash
from werkzeug.security import generate_password_hash
from helpers import apology, login_required, lookup, usd

# NEW import declarations
from helpers import return_shares, return_symbols, return_share_price, return_value
from helpers import datetime_format
from json import dumps


# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Additional custom filter
app.jinja_env.filters["datetime_format"] = datetime_format

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    # Ensure responses aren't cached
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    # Show portfolio of stocks
    # return apology("TODO")
    # print(f"session['user_id']: {session['user_id']}")

    # stock_portfolio = db.execute("SELECT * FROM tickers WHERE user_id = ? ORDER BY transaction_date DESC", session['user_id'])

    # stock_portfolio = db.execute( "SELECT id, sub_total, user_id, transaction_date, transaction_details, symbol, stock_price, SUM(shares) AS net_shares FROM tickers WHERE user_id = ? GROUP BY symbol ORDER BY transaction_date DESC" , session['user_id'] )

    # stock_portfolio = db.execute( "SELECT sub_total, user_id, transaction_date, symbol, stock_price, SUM(shares) AS net_shares FROM tickers WHERE user_id = ? GROUP BY symbol ORDER BY transaction_date DESC" , session['user_id'] )

    # stock_portfolio = db.execute(
    #     "SELECT sub_total, user_id, symbol, stock_price, SUM(shares) AS net_shares FROM tickers WHERE user_id = ? GROUP BY symbol ORDER BY transaction_date DESC"
    #     , session['user_id']
    # )

    stock_portfolio = db.execute(
        "SELECT sub_total, user_id, symbol, stock_price, SUM(shares) AS net_shares FROM tickers WHERE user_id = ? GROUP BY symbol HAVING net_shares > 0 ORDER BY transaction_date DESC",
        session["user_id"],
    )

    # print(f"\nstock_portfolio: {stock_portfolio}")
    # print(f"\nlen(stock_portfolio): {len(stock_portfolio)}")

    authorized_user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
    # print(f"\nauthorized_user: { authorized_user }")

    cash_on_hand = authorized_user[0]["cash"]
    username = authorized_user[0]["username"]

    # def return_shares(dict): [ etc, etc...]

    mapped_shares = list(map(return_shares, stock_portfolio))
    # print(f"\nmapped_shares: {mapped_shares}") # [50, 10]

    mapped_symbols = list(map(return_symbols, stock_portfolio))
    # print(f"\nmapped_symbols: {mapped_symbols}") # ['YUM', 'FNMA']

    mapped_prices = list(map(return_share_price, stock_portfolio))
    # print(f"\nmapped_prices: {mapped_prices}") # [118.38, 0.64]

    mapped_values = list(map(return_value, stock_portfolio))
    # print(f"\nmapped_products: {mapped_values}") # [5919.0, 6.4]

    special_length = list(range(1, len(mapped_symbols) + 1))
    # print(f"\nspecial_length: {special_length}") # [1,2]

    stocks_dictionary = {
        LEN: {
            "symbol": SYMB,
            "shares": SHRS,
            "price": PRCE,
            "value": VALU,
        }
        for LEN, SYMB, SHRS, PRCE, VALU in zip(
            special_length, mapped_symbols, mapped_shares, mapped_prices, mapped_values
        )
    }

    # print(f"\nstocks_dictionary: {stocks_dictionary}")
    # print(f"len(stocks_dictionary): {len(stocks_dictionary)}")

    current_value = 0
    # iterating key value pair
    for key, value in stocks_dictionary.items():
        # isolate the 'value' field
        if value and "value" in value.keys():
            # Add value of 'value' to current_value
            current_value += value["value"]

    # print(f"current_value: {current_value}")

    grand_total = cash_on_hand + current_value

    user_dictionary = {
        "cash_on_hand": cash_on_hand,
        "username": username,
        "grand_total": grand_total,
        "current_value": current_value,
    }

    # print(f"user_dictionary: {user_dictionary}")

    if request.method == "POST":
        return "POST"
    elif request.method == "GET":
        return render_template(
            "index.html",
            user_dictionary=user_dictionary,
            stock_portfolio=stock_portfolio,
            stocks_dictionary=stocks_dictionary,
        )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    # Buy shares of stock
    # return apology("TODO")
    # print(f"session: {session}") # <FileSystemSession {'user_id': 4}>
    # print(f"type(session['user_id']): {type(session['user_id'])}") # <class 'int'>
    authorized_user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
    # print(f"authorized_user: { authorized_user }")

    if request.method == "POST":
        shares = request.form.get("shares")
        ticker_text = request.form.get("symbol")

        try:
            shares = int(shares)
        except ValueError as derrp:
            # print(f"derrp: {derrp}")
            return apology("no fractions; only integers")

        if shares < 0:
            return apology("positive integers only")
        # print(f"shares: {shares}")

        if len(ticker_text) == 0:
            return apology("symbol is required")

        ticker_symbol = lookup(ticker_text)
        if ticker_symbol == None:
            return apology(ticker_text + " not a valid entry")
        # print(f"ticker_symbol: {ticker_symbol}")

        stock_price = ticker_symbol["price"]
        # print(f"stock_price: {stock_price}")

        sub_total = round(stock_price * shares, 2)
        # print(f"sub_total: {sub_total}")

        cash_on_hand = authorized_user[0]["cash"]
        # print(f"cash_on_hand: {cash_on_hand}")

        if sub_total > cash_on_hand:
            return apology("not enough funds")

        leftover_cash = round(cash_on_hand - sub_total, 2)
        # print(f"leftover_cash: {leftover_cash}")

        transaction_object = {
            "symbol": ticker_symbol["symbol"],
            "stock_price": stock_price,
            "shares": shares,
            "sub_total": sub_total,
        }
        # print(f"transaction_object: {transaction_object}")

        transaction_string = dumps(transaction_object)
        # print(f"transaction_string: {transaction_string}")

        try:
            update_one_query = db.execute(
                "UPDATE users SET cash = (?) WHERE id = (?)",
                leftover_cash,
                authorized_user[0]["id"],
            )

            if update_one_query != 1:
                return apology("new update is SNAFU")
            # print(f"update_one_query: {update_one_query}")

        except RuntimeError as berrp:
            return apology(berrp)

        try:
            insertion_query = db.execute(
                "INSERT INTO tickers (sub_total, user_id, transaction_details, symbol, stock_price, shares) VALUES (?,?,?,?,?,?)",
                sub_total,
                authorized_user[0]["id"],
                transaction_string,
                ticker_symbol["symbol"],
                stock_price,
                shares,
            )

            if insertion_query < 1:
                return apology("new insertion is SNAFU")
            # print(f"insertion_query: {insertion_query}")

        except RuntimeError as derrp:
            print(f"INSERTION RuntimeError: {derrp}")
            return apology(derrp)

        # return "POST"

        # Redirect user to home page
        return redirect("/")

    elif request.method == "GET":
        return render_template("buy.html", authorized_user=authorized_user)


@app.route("/history")
@login_required
def history():
    # Show history of transactions
    # return apology("TODO")

    # print(f"session['user_id']: {session['user_id']}")

    stock_portfolio = db.execute(
        "SELECT * FROM tickers WHERE user_id = ? ORDER BY transaction_date DESC",
        session["user_id"],
    )

    # print(f"\nstock_portfolio: {stock_portfolio}")
    # print(f"\nlen(stock_portfolio): {len(stock_portfolio)}")

    if request.method == "GET":
        return render_template("history.html", stock_portfolio=stock_portfolio)


@app.route("/login", methods=["GET", "POST"])
def login():
    # Log user in

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    # Log user out

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    # Get stock quote.
    # return apology("TODO")
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol")

        if request.form.get("symbol"):
            ticker_text = request.form.get("symbol")
            # print(f"ticker_text: {ticker_text}")

            # if not ticker_text:
            #     return apology("must provide symbol")

            ticker_symbol = lookup(ticker_text)
            # print(f"ticker_symbol: {ticker_symbol}")

            # if ticker_symbol == None:
            #     return apology("invalid request")

            if not ticker_symbol:
                return apology("invalid request")

            # return "POST"
            return render_template("quote.html", symbol=ticker_symbol)
    elif request.method == "GET":
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    # Register user
    # return apology("TODO")

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # Ensure username DOES NOT exist...
        elif (
            len(
                db.execute(
                    "SELECT * FROM users WHERE username = ?",
                    request.form.get("username"),
                )
            )
            == 1
        ):
            return apology("username exists")

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # Ensure confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide confirmation")

        # Ensure plain-text password and plain-text confirmation, indeed, match
        elif not request.form.get("password") == request.form.get("confirmation"):
            return apology("password must match")

        username = request.form.get("username")
        hashed = generate_password_hash(
            request.form.get("password"), method="pbkdf2", salt_length=16
        )

        insertion_query = db.execute(
            "INSERT INTO users (username, hash) VALUES (?,?)", username, hashed
        )
        # print(f"insertion_query: {insertion_query}")

        return redirect("/login")
        # return "POST"

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    # Sell shares of stock
    # return apology("TODO")

    # print(f"session['user_id']: {session['user_id']}")

    # stock_portfolio = db.execute("SELECT * FROM tickers WHERE user_id = ? ORDER BY transaction_date DESC", session['user_id'])

    # stock_portfolio = db.execute( "SELECT id, sub_total, user_id, transaction_date, transaction_details, symbol, stock_price, SUM(shares) AS net_shares FROM tickers WHERE user_id = ? GROUP BY symbol ORDER BY transaction_date DESC" , session['user_id'] )

    # stock_portfolio = db.execute( "SELECT sub_total, user_id, transaction_date, symbol, stock_price, SUM(shares) AS net_shares FROM tickers WHERE user_id = ? GROUP BY symbol ORDER BY transaction_date DESC" , session['user_id'] )

    # stock_portfolio = db.execute(
    #     "SELECT sub_total, user_id, symbol, stock_price, SUM(shares) AS net_shares FROM tickers WHERE user_id = ? GROUP BY symbol ORDER BY transaction_date DESC"
    #     , session['user_id']
    # )

    stock_portfolio = db.execute(
        "SELECT sub_total, user_id, symbol, stock_price, SUM(shares) AS net_shares FROM tickers WHERE user_id = ? GROUP BY symbol HAVING net_shares > 0 ORDER BY transaction_date DESC",
        session["user_id"],
    )

    # print(f"\nstock_portfolio: {stock_portfolio}")
    # print(f"\nlen(stock_portfolio): {len(stock_portfolio)}")

    authorized_user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
    # print(f"\nauthorized_user: { authorized_user }")

    # mapped_symbols = [ "AAAA", "BBBB", "CCCC" ]

    # def return_shares(dict): [ etc, etc...]

    mapped_shares = list(map(return_shares, stock_portfolio))
    # print(f"\nmapped_shares: {mapped_shares}") # [50, 10]

    mapped_symbols = list(map(return_symbols, stock_portfolio))
    # print(f"\nmapped_symbols: {mapped_symbols}") # ['YUM', 'FNMA']

    mapped_prices = list(map(return_share_price, stock_portfolio))
    # print(f"\nmapped_prices: {mapped_prices}") # [118.38, 0.64]

    mapped_values = list(map(return_value, stock_portfolio))
    # print(f"\nmapped_products: {mapped_values}") # [5919.0, 6.4]

    special_length = list(range(1, len(mapped_symbols) + 1))
    # print(f"\nspecial_length: {special_length}") # [1,2]

    stocks_dictionary = {
        LEN: {
            "symbol": SYMB,
            "shares": SHRS,
            "price": PRCE,
            "value": VALU,
        }
        for LEN, SYMB, SHRS, PRCE, VALU in zip(
            special_length, mapped_symbols, mapped_shares, mapped_prices, mapped_values
        )
    }

    # print(f"\nstocks_dictionary: {stocks_dictionary}")
    # print(f"len(stocks_dictionary): {len(stocks_dictionary)}")

    if request.method == "POST":
        # ImmutableMultiDict([('symbol', 'AAAA'), ('shares', '4')])
        # print(f"\nsell ~ request.form: {request.form}")

        # Validate shares
        shares = request.form.get("shares")

        if not shares:
            return apology("missing amount of shares")

        try:
            shares = int(shares)
        except ValueError as qerrp:
            # print(f"qerrp: {qerrp}")
            return apology("no fractions; only integers")

        if shares < 0:
            return apology("positive integers only")
        # print(f"shares: {shares}")

        # Validate symbol
        symbol = request.form.get("symbol")

        if not symbol:
            return apology("missing symbol")

        if symbol not in mapped_symbols:
            return apology(f"{symbol} not a valid symbol")

        temp_dict = {}
        for k1 in stocks_dictionary:
            v1 = stocks_dictionary[k1]
            # print(f"k1: {k1} - v1: {v1}")
            for k2 in stocks_dictionary[k1]:
                # v2 = stocks_dictionary[k1][k2]
                if k2 == "symbol":
                    if stocks_dictionary[k1][k2] == symbol:
                        # print(f"k2: {k2} - v2: {stocks_dictionary[k1][k2]}")
                        # print(f"stocks_dictionary[k1]: {stocks_dictionary[k1]}")
                        temp_dict = stocks_dictionary[k1].copy()

        share_limit = temp_dict["shares"]
        stock_price = temp_dict["price"]

        if shares > share_limit:
            return apology(f"you own {share_limit} shares of {symbol}")

        cash_on_hand = authorized_user[0]["cash"]
        # print(f"\ncash_on_hand: {cash_on_hand}")

        sub_total = round(stock_price * shares, 2)
        # print(f"\nsub_total: {sub_total}")

        available_cash = round(cash_on_hand + sub_total, 2)
        # print(f"\navailable_cash: {available_cash}")

        transaction_object = {
            "symbol": symbol,
            "stock_price": stock_price,
            "shares": shares,
            "sub_total": sub_total,
        }
        # print(f"\ntransaction_object: {transaction_object}")

        transaction_string = dumps(transaction_object)
        # print(f"\ntransaction_string: {transaction_string}")

        try:
            update_one_query = db.execute(
                # "UPDATE badmofo SET chimichanga = (?) WHERE id = (?)",
                "UPDATE users SET cash = (?) WHERE id = (?)",
                available_cash,
                authorized_user[0]["id"],
            )

            if update_one_query != 1:
                return apology("new update is SNAFU")
            # print(f"update_one_query: {update_one_query}")

        except RuntimeError as berrp:
            return apology(berrp)

        try:
            insertion_query = db.execute(
                "INSERT INTO tickers (sub_total, user_id, transaction_details, symbol, stock_price, shares) VALUES (?,?,?,?,?,?)",
                sub_total,
                authorized_user[0]["id"],
                transaction_string,
                symbol,
                stock_price,
                (-1 * shares),
            )

            if insertion_query < 1:
                return apology("new insertion is SNAFU")
            # print(f"insertion_query: {insertion_query}")

        except RuntimeError as derrp:
            print(f"INSERTION RuntimeError: {derrp}")
            return apology(derrp)

        # return "POST"
        # Redirect user to home page
        temp_dict.clear()  # DO NOT FORGET TO UNCOMMENT THIS STEP
        return redirect("/")
        # return "POST"

    elif request.method == "GET":
        # print(f"index ~ request: {request}")
        # print(f"request.args: {request.args}")
        # return render_template("sell.html")
        return render_template(
            "sell.html", mapped_symbols=mapped_symbols, authorized_user=authorized_user
        )


@app.route("/change_password", methods=["GET", "POST"])
def change_password():
    # Change password

    authorized_user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
    # print(f"authorized_user: { authorized_user }")

    if request.method == "POST":
        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", authorized_user[0]["username"]
        )

        # Ensure current pdub was submitted
        if not request.form.get("current_password"):
            return apology("must provide current password")

        # Ensure new pdub was submitted
        elif not request.form.get("new_password"):
            return apology("must provide new password")

        # Ensure confirm pdub was submitted
        elif not request.form.get("confirm_new_password"):
            return apology("must confirm new password")

        # Ensure plain-text fields match
        elif not request.form.get("new_password") == request.form.get(
            "confirm_new_password"
        ):
            return apology("password must match")

        # Ensure username exists and password is correct
        elif len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("current_password")
        ):
            return apology(
                "invalid password", 403
            )  # return apology("invalid username and/or password", 403)

        hashed = generate_password_hash(
            request.form.get("new_password"), method="pbkdf2", salt_length=16
        )

        try:
            update_pdub_query = db.execute(
                "UPDATE users SET hash = (?) WHERE id = (?)", hashed, session["user_id"]
            )

            if update_pdub_query != 1:
                return apology("password update is SNAFU")
            # print(f"\nupdate_pdub_query: {update_pdub_query}")

        except RuntimeError as glerrp:
            return apology(glerrp)

        # Crush current session!
        return redirect("/logout")
        # return "POST"

    elif request.method == "GET":
        return render_template("change_password.html")


@app.route("/add_cash", methods=["GET", "POST"])
def add_cash():
    # Add cash
    authorized_user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
    # print(f"authorized_user: { authorized_user }")

    if request.method == "POST":
        cash_amount_added = request.form.get("cash_amount_added")
        amount_confirmed = request.form.get("amount_confirmed")

        try:
            cash_amount_added = float(cash_amount_added)
        except ValueError as derrp:
            # print(f"derrp: {derrp}")
            return apology("amount not numeric")

        try:
            amount_confirmed = float(amount_confirmed)
        except ValueError as derrp:
            # print(f"derrp: {derrp}")
            return apology("amount not numeric")

        if cash_amount_added < 0:
            return apology("positive amounts only")
        # print(f"cash_amount_added: {cash_amount_added}")

        if amount_confirmed < 0:
            return apology("positive amounts only")
        # print(f"amount_confirmed: {amount_confirmed}")

        if not cash_amount_added:
            return apology("cash amount required")

        elif not amount_confirmed:
            return apology("amount confirmation required")

        # Ensure amount fields match
        elif not cash_amount_added == amount_confirmed:
            return apology("cash amounts must match")

        available_cash = round(authorized_user[0]["cash"] + cash_amount_added, 2)

        try:
            update_cash_amount_query = db.execute(
                "UPDATE users SET cash = (?) WHERE id = (?)",
                available_cash,
                authorized_user[0]["id"],
            )

            if update_cash_amount_query != 1:
                return apology("cash update is SNAFU")
            # print(f"update_cash_amount_query: {update_cash_amount_query}")

        except RuntimeError as zerrp:
            return apology(zerrp)

        # Redirect user to home page
        return redirect("/")

        # return "POST"

    elif request.method == "GET":
        return render_template("add_cash.html")


# flask run
