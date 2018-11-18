
import numpy 
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


# In[6]:

#iniciamos con la grafica de las trayectorias:
files=('@10°.txt','@20°.txt','@30°.txt','@40°.txt','@45°.txt','@50°.txt','@60°.txt','@70°.txt')
titles=('10°','20°','30°','40°','45°','50°','60°','70°')
for i in range(8):
    info=numpy.loadtxt(files[i],float, delimiter=',')
    plt.plot(info[:,1],info[:,2])
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('trayectoria a '+titles[i])
    plt.savefig('trayectoria_'+titles[i]+'.pdf')
    plt.hold(False)

