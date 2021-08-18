import kf_cpp
import numpy as np

kf_cpp.pass_str(3.0,"this num is ")
# a1 = np.array([[0,0,0],[1,0,0],[1,1,0],[0,1,0],[0,0,1],[1,0,1],[1,1,1],[0,1,1]])
a1 = np.array([[1,-9],[15,3],[2,0],[-1,-9]])
a2 = np.array([1,3,0,4])
print("type(a1):\n",type(a1))
kf_cpp.sum_array(a1)
kf_cpp.sum_array(a2)