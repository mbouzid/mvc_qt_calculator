CXX		= g++
CXXFLAGS= -Wall
INC		= -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LIBS	= -lQtGui -lQtCore
STD		= -std=c++11
LINK	= g++
RM		= rm

###### Files

SOURCES		= main.cpp 
OBJECTS		= main.o model.o moc_controller.o 
TARGET		= tp2


####### Building rules

all: $(TARGET) clean
	@echo "Building complete."

####### Linking

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIBS) $(STD)
	@echo "Linking done."

###### Meta object compiling

moc_controller.cpp: controller.hpp
	@echo "Meta object compiling."
	moc $(INC) controller.hpp -o moc_controller.cpp

###### Compiling

main.o: main.cpp view.hpp
	@echo "Compiling."
	$(CXX) -c $(CXXFLAGS) $(INC) -o main.o main.cpp $(STD)
model.o: model.cpp
	@echo "Compiling."
	$(CXX) -c $(CXXFLAGS) $(INC) -o model.o model.cpp $(STD)
moc_controller.o: moc_controller.cpp
	@echo "Compiling."
	$(CXX) -c $(CXXFLAGS) $(INC) -o moc_controller.o moc_controller.cpp $(STD)

##### Cleaning

clean: $(OBJECTS)
	$(RM) $(OBJECTS)
	@echo "Cleaning done."
	
