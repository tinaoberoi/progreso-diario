# Problem1
class Line:
    
    def __init__(self,coor1,coor2):
    	print("Created Line")
    	self.coor1_x = coor1[0]
    	self.coor1_y = coor1[1]
    	self.coor2_x = coor2[0]
    	self.coor2_y = coor2[1]
    
    def distance(self):
    	print(((self.coor1_x-self.coor2_x)**2 + (self.coor1_y - self.coor2_y)**2)**0.5)
    
    def slope(self):
        print((self.coor1_y-self.coor2_y)/(self.coor1_x-self.coor2_x))

coordinate1 = (3,2)
coordinate2 = (8,10)

li = Line(coordinate1,coordinate2)
li.distance()
li.slope()

# Problem2
class Cylinder:
    pi = 3.14
    def __init__(self,height=1,radius=1):
        self.height = height
        self.radius = radius
        
    def volume(self):
        print(self.pi * (self.radius**2) * self.height)
    
    def surface_area(self):
        print(2*self.pi*self.radius*self.height + 2*self.pi*(self.radius)**2)


c = Cylinder(2,3)
c.volume()
c.surface_area()