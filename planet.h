#include"Header.h"
#pragma once
class planet
{

public:
	planet(double radius, sf::Vector2f position, sf::Vector2f velocity, float mass, const std::string& name, sf::Color color)
	   :shape(radius), position(position), velocity(velocity), m(mass), name(name), color(color), rad(radius) {
		shape.setPosition(position);
		shape.setFillColor(color);
	}
	planet() {
		m = 0.0;
		rad = 0.0;
		trajectory_status = 0;
		trajectory_length = 0;
		trajectory_radius = 0.0;
		count = 0;
		shape.setRadius(0);
		position.x = 0;
		position.y = 0;
		shape.setPosition(position.x, position.y);
		velocity.x = 0;
		velocity.y = 0;
		shape.move(velocity.x, velocity.y);
		name = "no_name";
		
	}
	void SetPosition(float x, float y) {
		position.x = x;
		position.y = y;
		shape.setPosition(x, y);
	}
	void SetRadius(double radius) {
		rad = radius;
		shape.setRadius(radius);
	}
	void SetColor(int r, int g,int b ) {
		color.r = r;
		color.g = g;
		color.b = b;
		shape.setFillColor(color);
	}
	void SetVelocity(float x, float y) {
		velocity.x = x;
		velocity.y = y;
	
		
		
	}
	void SetName(string& name) {
		
		this->name = name;
	}
	void SetMass(float mass) {
		m = mass;
	}
	
	void draw(sf::RenderWindow& window) {
		if (trajectory_status) {
			
			trajectory_points.resize(trajectory_length);
			trajectory_coordinates.resize(trajectory_length);

			trajectory_points[count].setFillColor(the_color_of_the_trajectory);
			trajectory_points[count].setRadius(5);

			trajectory_coordinates[count] = GetPos();
			trajectory_points[count].setPosition(trajectory_coordinates[count]);
			
			count++;
			if (count >= trajectory_length) count = 0;
			for (int i = 0; i < trajectory_length; i++)
			{
				window.draw(trajectory_points[i]);
			}
		}
		window.draw(shape);
	}

	void move( ) {
		
		shape.move(velocity.x, velocity.y);
	}

	void turn_on_the_trajectory() {
		trajectory_status = 1;
	}
	void disable_the_trajectory() {
		trajectory_status = 0;
	}
	void set_the_length_of_the_trajectory( int number) {
		trajectory_length = number;
	}

	void set_the_color_of_the_trajectory(int r, int g, int b) {
		the_color_of_the_trajectory.r = r;
		the_color_of_the_trajectory.g = g;
		the_color_of_the_trajectory.b = b;

	}

	void set_the_radius_of_the_trajectory(float r) {
		trajectory_radius = r;
	}

	//============================================================
	float  get_the_radius_of_the_trajectory() {
		return trajectory_radius;
	}
	bool get_trajectory_status() {
		return trajectory_status;
	}
	int set_the_length_of_the_trajectory() {
		return trajectory_length;
	}
	Color get_the_color_of_the_trajectory() {
		return the_color_of_the_trajectory;
	}
	Vector2f GetPos() {
		position = shape.getPosition();
		return position;
	}
	Vector2f GetVelocity() {
		return velocity;
	}
	Color GetColor() {
		return color;
	}
	string GetName() {
		return name;
	}
	float GetRadius() {
		return rad;
	}
	float GetMass() {
		return m;
	}
	
	
private:
	float m = 0.0;
	float rad = 0.0;
	float trajectory_radius = 0.0;
	bool trajectory_status = 0;
	int trajectory_length = 0;
	int count = 0;
	vector<Vector2f> trajectory_coordinates;
	vector<CircleShape> trajectory_points;
	sf::CircleShape shape;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	sf::Color the_color_of_the_trajectory;
   std::string name;
	
};


