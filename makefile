phase.png : tray.txt
	python JG_graph.py
tray.txt : a.out
	./a.out > tray.txt
a.out:
	c++ JG_gravity.cpp
clean :
	rm phase.png pos.png vel.png tray.txt a.out
