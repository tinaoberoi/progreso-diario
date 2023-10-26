# Special Methods
* Classes in Python can implement certain operations with special method names.
* These methods are not actually called directly but by Python specific language syntax.

```python
class Book:
    def __init__(self, title, author, pages):
        print("A book is created")
        self.title = title
        self.author = author
        self.pages = pages

    def __str__(self):
        return "Title: %s, author: %s, pages: %s" %(self.title, self.author, self.pages)

    def __len__(self):
        return self.pages

    def __del__(self):
        print("A book is destroyed")

book = Book("Python Rocks!", "Jose Portilla", 159)

#Special Methods
print(book)
print(len(book))
del book
```
A book is created
Title: Python Rocks!, author: Jose Portilla, pages: 159
159
A book is destroyed

* The __init__(), __str__(), __len__() and __del__() methods are special methods.
*These special methods are defined by their use of underscores. They allow us to use Python specific functions on objects created through our class.