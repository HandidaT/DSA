class BinaryTree:
  def __init__(self, initialvalue=None):
    self.value=initialvalue
    if self.value:
      self.left=BinaryTree()
      self.right=BinaryTree()
    else:
      self.left=None
      self.right=None
    return
  def isempty(self):
    return(self.value==None)
  def isleaf(self):
    return(self.left.isempty() and self.right.isempty())
  def inorder(self):
    if self.isempty():
      return([])
    else:
      return(
        self.left.inorder() +
        [self.value]+
        self.right.inorder()
        )
  def __str__(self):
    return(str(self.inorder()))
  def find(self,v):
    if self.isempty():
      return(False)
    if self.value==v:
      return(True)
    if v<self.value:
      return(self.left.find(v))
    else:
      return(self.right.find(v))
  def minval(self):
    if self.left==None:
      return(self.value)
    else:
      return(self.left.minval())
  def maxval(self):
    if self.right==None:
      return(self.value)
    else:
      return(self.right.maxval())
  def insert(self,v):
    if self.isempty():
      self.value=v
      self.left=BinaryTree()
      self.right=BinaryTree()
    if self.value==v:
      return
    if v<self.value:
      self.left.insert(v)
      return
    if v>self.value:
      self.right.insert(v)
      return
  def delete(self,v):
    if self.isempty():
      return
    if v<self.value:
      self.left.delete(v)
      return
    if v>self.value:
      self.right.delete(v)
      return
    if v==self.value:
      if self.isleaf():
        self.makeempty()
      elif self.left.isempty():
        self.copyright()
      else:
        self.value=self.left.maxval()
        self.left.delete(self.left.maxval())
      return
  def makeempty(self):
    self.value=None
    self.left=None
    self.right=None
    return
  def copyright(self):
    self.value=self.right.value
    self.left=self.right.left
    self.right=selft.right.right
    return
  def foo(self):
    if self.isempty():
      print("isempty")
      return(0)
    elif self.isleaf():
      print("isleaf ret 1",self.value)
      return(1)
    else:
      return(self.left.foo() + self.right.foo())

bitree1=BinaryTree()
for i in [1,3,2,18,7,5,4,22,14]:
  bitree1.insert(i)
  print(bitree1)
bitree1.insert(17)
bitree1.insert(30)
#bitree1.delete(3)
print(bitree1.foo())
print(bitree1)
