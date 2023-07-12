import datetime

fullname = "le thanh tai"
Information = {
    "favorite": "Singing",
    "Sex": "Male",
    "College": "UIT",
    "Birth": 2005
}

This_year = datetime.datetime.now().year
Age = This_year - Information["Birth"]
print(Age)

if Age > 18 and Information["College"] == "UIT":
    print("Congratulations")
elif Age < 18:
    if Information["favorite"] == "Singing":
        print("Dude! Do it!")
    else:
        print("Just working for this time!")
