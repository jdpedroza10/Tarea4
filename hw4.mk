#Dependencias
all: average_temperature_caso_1.png  caso_1_t0s.png  trayectoria_70.png


average_temperature_caso_1.png  caso_1_t0s.png  trayectoria_70.png: solution_1.txt solution_2.txt solution_3.txt a10.txt a20.txt a30.txt a40.txt a45.txt a50.txt a60.txt a70.txt
	python3 Plots_hw4.py

solution_1.txt solution_2.txt solution_3.txt:
	# compilar c++
	# ignorarndo warnings
	g++ PDE.cpp -o calor_calcita.x
	./calor_calcita.x

a10.txt a20.txt a30.txt a40.txt a45.txt a50.txt a60.txt a70.txt:
	# compilar c++
	# ignorarndo warnings
	g++ ODE.cpp -w -o lanzamiento_con_friccion.x
	./lanzamiento_con_friccion.x

