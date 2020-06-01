# Inro to YAML
* It is used to represent data just like JSON/XML.
* You have key value pairs. Ex: 
Fruit: Apple
Vegetable: Carrot
**Note:** There has to a space b/w ":" and another character.

* Lists/Array in Yaml(ordered collection)
```yaml
Fruits:
-  Orange
-  Apple
Vegetables:
-  Carrot
-  Potato
```
```
Banana1:
    Calories: 105
    Fat: 0.4g
    Carbs: 27g
Banana2:
    Calories: 105
    Carbs: 27g
    Fat: 0.4g
    
```
Suppose we have 2 lists:
Banana1 != Banana2
Here "-" indicates that this is an item of list.

* Dictionary (Unordered collection)
```yaml
Banana:
    Calories: 105
    Fat: 0.4g
    Carbs: 27g

Grapes:
    Calories: 62
    Fat: 0.3g
    Carbs: 16g
```
Suppose we have 2 dictionaries:
```
Banana1:
    Calories: 105
    Fat: 0.4g
    Carbs: 27g
Banana2:
    Calories: 105
    Carbs: 27g
    Fat: 0.4g
    
```

Banana1 != Banana2
* For comment use #
**NOTE**
- Make sure they have the right amount of spaces to represent data correctly.

