# Optional Lab(s) 7 by Luis Artavia - Hall of Prophecy
# draft processed on: September 14, 2023
# Composed on: September 14, 2023
# Practice document not intended for evaluation

# sqlite3 roster.db '.dump' > dump.sql
# sqlite3 roster.db

# Read content of present database
# *Possibly read schema of present database

from cs50 import SQL

url_string = "sqlite:///roster.db"
db = SQL(url_string)
# print(f"DEV ONLY ~ db: \n{db}") # <cs50.sql.SQL object at 0x7f039debfcd0>
# All records

select_students_query = db.execute("SELECT * FROM students")
# print(f"DEV ONLY ~ select_students_query: \n{select_students_query}")

# for student in select_students_query:
#     print(
#         f"{student['id']}  |  {student['student_name']}  |  {student['house']} |  {student['head']}"
#     )

# print(f"len(select_students_query): {len(select_students_query)}")
# for i in range(1, len(select_students_query) + 1):
# print(f"{i} " , end="")
# print()

# Create NEW houses table
# Returns True

try:
    create_houses_query = db.execute(
        "CREATE TABLE houses ( id INTEGER, house TEXT, head TEXT, PRIMARY KEY(id) )"
    )
    print(f"DEV ONLY ~ create_houses_query: \n{create_houses_query}")
except RuntimeError as yerrp:
    print(yerrp)

# Create NEW assignments table
# Returns True

try:
    create_assignments_query = db.execute(
        "CREATE TABLE assignments ( student_id INTEGER NOT NULL, house_id INTEGER NOT NULL, FOREIGN KEY(student_id) REFERENCES students(id), FOREIGN KEY(house_id) REFERENCES houses(id), PRIMARY KEY(student_id, house_id) )"
    )
    print(f"DEV ONLY ~ create_assignments_query: \n{create_assignments_query}")
except RuntimeError as xerrp:
    print(xerrp)

# All distinct records

select_houses_query = db.execute(
    "SELECT DISTINCT house, head FROM students ORDER BY house ASC"
)
print(f"DEV ONLY ~ select_houses_query: {select_houses_query}")

for i in range(1, len(select_houses_query) + 1):
    try:
        house_insertion_query = db.execute(
            "INSERT INTO houses (id, house, head) VALUES (?, ?, ?)",
            int(i),
            select_houses_query[i - 1]["house"],
            select_houses_query[i - 1]["head"],
        )
        print(f"house_insertion_query: {house_insertion_query}")
    except RuntimeError as werrp:
        print(werrp)

# All distinct records

select_assignments_query = db.execute(
    "SELECT students.id AS student_id, houses.id AS house_id FROM students JOIN houses ON students.house = houses.house"
)
# print(f"DEV ONLY ~ select_assignments_query: {select_assignments_query}")

for i in range(1, len(select_assignments_query) + 1):
    try:
        assignment_insertion_query = db.execute(
            "INSERT INTO assignments (student_id, house_id) VALUES (?, ?)",
            select_assignments_query[i - 1]["student_id"],
            select_assignments_query[i - 1]["house_id"],
        )
        print(f"assignment_insertion_query: {assignment_insertion_query}")
    except RuntimeError as werrp:
        print(werrp)

# find . -type f -iname 'roster.db' -exec chmod 664 {} \;
# Alter the students table and cull each the house and head columns

try:
    drop_house_column_query = db.execute("ALTER TABLE students DROP COLUMN house")
    print(f"drop_house_column_query: {drop_house_column_query}")
except RuntimeError as verrp:
    print(verrp)

try:
    drop_head_column_query = db.execute("ALTER TABLE students DROP COLUMN head")
    print(f"drop_head_column_query: {drop_head_column_query}")
except RuntimeError as verrp:
    print(verrp)

new_join_query = db.execute(
    "SELECT * FROM students JOIN assignments ON students.id = assignments.student_id JOIN houses ON houses.id = assignments.house_id"
)
# print(f"DEV ONLY ~ new_join_query: \n{new_join_query}")

for student in new_join_query:
    print(f"{student}")

# find . -type f -iname 'roster.db' -exec chmod 644 {} \;
# python3 refactor_roster_db.py
