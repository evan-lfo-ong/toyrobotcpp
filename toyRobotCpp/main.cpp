﻿// toyRobotCpp.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>
#include "ToyRobot.hpp"
#include "TableEnvironment.hpp"

using namespace std;
using namespace ToyRobotNS;

int main()
{
	try {
		ToyRobot robot(new TableEnvironment());
		robot.place(0, 0, "SOUTH");
		robot.move();
		robot.left();
		robot.move();
		robot.right();
		cout << robot.report();
		char c;
		cin >> c;
	}
	catch (ToyRobotException ex) {
		cout << ex.getMessage() << endl;
	}
	return 0;
}
