class Parent(object):
  def __init__(self):
    self.value = 5

class GFriend(object):
  def __init__(self):
    self.value = 0

def get_value(self):
  return self.value

class Child(Parent):
  def get_value(self):
    return self.value + 1

class Child1(GFriend):
  def get_value(self):
    return self.value + 1

class Summary:

  def __init__(self, x):
    if x == 0:
      self.obj = Child()
    elif x == 1:
      self.obj = Child1()

  def get_value(self):
    return self.obj.get_value()


print Summary(0).get_value()
