# Optional Lab(s) 6 by Luis Artavia - bank
# draft processed on: August 30, 2023
# Composed on: August 30, 2023
# Practice document not intended for evaluation

def string_reward(n):
  molded = "$" + str(n)
  print(molded)

cash_reward = 100

# greeting = "Hello Newman"
# greeting = "Hey dude"
# greeting = "Wadya want"
# greeting = "Damn homey"
greeting = input("Enter a greeting sans any punctuation: ")

# print(f"{greeting}")

words = greeting.split()
# print(words)

for word in words[0:1]:
  """
  print(f"word: {word}")
  """
  if word.lower() == "hello" or word.lower() == "hello,":
    cash_reward = 0
    break
  for c in word[0:1]:
    """
    print(f"c: {c}")
    """
    if c.lower() == "h":
      cash_reward = 20
      break

"""
print(cash_reward)
"""
string_reward(cash_reward)