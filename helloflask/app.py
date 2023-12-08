# Optional Lab 9 by Luis Artavia - helloflask
# draft processed on: October 03, 2023
# Composed on: October 03, 2023
# Practice document not intended for evaluation

from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        return render_template("index.html")
    else:
        print("Form submitted!")
        color = request.form.get("color")
        return render_template("color.html", color=color)


"""
@app.route("/")
def index():
    return render_template("index.html")
"""

"""
@app.route("/")
def index():
    return "Hello, World!"
"""
