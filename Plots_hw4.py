# coding: utf-8

# In[1]:

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

# In[13]:

#segundo apartado: graficas de la temperatura para diferentes tiempos en los tres casos estudiados:
#cargamos las coordenadas de los puntos
meshgrid=numpy.loadtxt('meshgrid.txt',float,delimiter=',')
x_coor=meshgrid[:,0]
y_coor=meshgrid[:,1]


# In[19]:

#ejecutamos un bucle para las graficas:
delta_t=(3,3,10)
pasos_de_tiempo=(10000,100000,100000)
grafica_temp = plt.figure()
for  i in range(3):#se hace una ejecuación por cada condicion de frontera establecida.
    for  j in range(4):#dentro del bucle anterior, se hace otro, con cada paso para cada grafica solicitada
        T_data=numpy.loadtxt('solution_'+str(i+1)+'.txt',float,delimiter=',',usecols=range(36))
        tiempo=numpy.linspace(0,pasos_de_tiempo[i]*delta_t[i],pasos_de_tiempo[i])
        grafica_tem_1 = grafica_temp.gca(projection='3d')
        grafica_tem_1.plot_trisurf(x_coor, y_coor, T_data[int(j*pasos_de_tiempo[i]/3-1)], cmap=plt.cm.inferno)
        grafica_temp.savefig('caso_'+str(i+1)+'_t='+str(int(j*pasos_de_tiempo[i]*delta_t[i]/3))+'s.pdf')
        grafica_temp.clear()
        grafica_temp.hold(True)
	# In[23]:

#finalmente las graficas de la temperatura en funcion del tiempo considerando al dominio como un sistema de parametros
#condensados:
plt.hold(False)
for i in range (3):
    T_data=numpy.loadtxt('solution_'+str(i+1)+'.txt',float,delimiter=',',usecols=range(36))
    T_prom=numpy.zeros(pasos_de_tiempo[i])
    #bucle para calcular la temperatura promedio en cada paso de tiempo:
    for j in range(pasos_de_tiempo[i]):
        T_prom[j]=sum(T_data[j,:])/36
    tiempo=numpy.linspace(0,pasos_de_tiempo[i]*delta_t[i],pasos_de_tiempo[i])
    plt.plot(tiempo,T_prom)
    plt.xlabel('t(s)')
    plt.ylabel('T(°C)')
    plt.title('caso '+str(i+1))
    plt.savefig('avarage_temperature_caso_'+str(i+1)+'.pdf')

# In[ ]:





