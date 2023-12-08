# Required Lab 9 by Luis Artavia - birthdays
# draft processed on: October 04, 2023
# submitted for grade on: October 04, 2023

# sqlite3 birthdays.db '.dump' > dump.sql
# sqlite3 birthdays.db

# .databases
# .tables
# .schema
# .mode table
# .headers ON

# import os
from cs50 import SQL
from flask import Flask, redirect, render_template, request

# from flask import flash, jsonify, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    # TODO: Display the entries in the database on index.html
    selection_query = db.execute("SELECT * FROM birthdays ORDER BY id ASC")
    # print(f"selection_query: {selection_query}")

    if request.method == "POST":
        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        derrplist = []

        if len(name) == 0:
            derrplist.append('The "name" cannot be blank.')
        if len(derrplist) > 0:
            # print(f"derrplist: { derrplist }")
            return render_template(
                "index.html", birthdays=selection_query, derrplist=derrplist
            )
        elif len(derrplist) == 0:
            # print(f"\n\nNo errors! derrplist: { derrplist }\n\n")
            insertion_query = db.execute(
                "INSERT INTO birthdays (name, month, day) VALUES (?,?,?)",
                name,
                month,
                day,
            )
            # print(f"insertion_query: {insertion_query}")
            return redirect("/")
    elif request.method == "GET":
        # TODO: Display the entries in the database on index.html
        # return render_template("index.html")
        return render_template("index.html", birthdays=selection_query)


@app.route("/remove", methods=["POST"])
def remove():
    if request.form.get("id"):
        # print(f"request.form.get('id'): {request.form.get('id')}")
        # return "POST"
        # DELETE FROM birthdays WHERE id = (?)
        deletion_query = db.execute(
            "DELETE FROM birthdays WHERE id = (?)", int(request.form.get("id"))
        )
        # print(f"deletion_query: {deletion_query}")
        return redirect("/")


@app.route("/view/<person_id>", methods=["GET"])
def view(person_id):
    # print(f"person_id: {person_id}")
    if request.method == "GET":
        # print(f"request.args: {request.args}")
        person = db.execute("SELECT * FROM birthdays WHERE id = (?)", int(person_id))
        # print(f"person ~ person: {person}")
        # return "GET"
        return render_template("view.html", person=person)


@app.route("/edit/<person_id>", methods=["GET"])
def edit(person_id):
    # print(f"person_id: {person_id}")
    if request.method == "GET":
        # print(f"request.args: {request.args}")
        person = db.execute("SELECT * FROM birthdays WHERE id = (?)", int(person_id))
        # print(f"person ~ person: {person}")
        # return "GET"
        return render_template("update.html", person=person)


@app.route("/update", methods=["POST"])
def update():
    if request.method == "POST":
        # UPDATE birthdays SET name = 'Charanko', day = 2, month = 28 WHERE id = 1;
        update_one_query = db.execute(
            "UPDATE birthdays SET name = (?), month = (?), day = (?) WHERE id = (?)",
            request.form.get("name"),
            int(request.form.get("month")),
            int(request.form.get("day")),
            int(request.form.get("id")),
        )
        # print(f"update_one_query: {update_one_query}")
        # return "POST"
        return redirect("/view/" + request.form.get("id"))
