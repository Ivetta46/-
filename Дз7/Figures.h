#ifndef UNTITLED8_FIGURES_H
#define UNTITLED8_FIGURES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Figure {
public:
    Figure() {
        std::cout << "Calling Figure.\n";
    }
    virtual ~Figure() {}
    virtual double getPerimeter() const = 0;
    virtual double getSquare() const = 0;
    virtual void getInformation() const = 0;
};

class ellipse : public Figure
{
private:
    double a, b;

public:
    ellipse(double x = 0, double y = 0) : a(std::max(x, y)), b(std::min(x, y))
    {
        std::cout << "Calling ellipse.\n";
    }
    virtual ~ellipse(){}
    virtual double getPerimeter() const override;
    virtual double getSquare() const override;
    virtual void getInformation() const override;

public:
    double getLarge() const { return a;}
    double getSmall() const { return b;}
    void setLarge(double tmp) { a = tmp;}
    void setSmall(double tmp) { b = tmp;}
};

class circle : public ellipse
{
private:
    double r;

public:
    circle(double tmp = 0) : r(tmp)
    {
        std::cout << "Calling circle.\n";
    }
    virtual ~circle(){}
    virtual double getPerimeter() const override final;
    virtual double getSquare() const override final;
    virtual void getInformation() const override final;

public:
    double getRadius() const { return r;}
    void setRadius(double tmp) { r = tmp;}
};

class Polygon : public Figure
{
private:
    int A;
protected:
    std::vector<double> Sides;
    Polygon(int tmp = 3) : A(tmp)
    {
        Sides.resize(A);
        std::cout << "Calling Polygon.\n";
    }
public:
    Polygon(int tmp, const std::vector<double>& tmp1) : A(tmp)
    {
        for (auto i = 0; i < A; i++)
            Sides.push_back(tmp1[i]);
        std::cout << "Calling Polygon.\n";
    }
    virtual ~Polygon()
    {
        Sides.clear();
    }
    virtual double getPerimeter() const = 0;
    virtual double getSquare() const = 0;
    virtual void getInformation() const = 0;

    double getA() const { return A;}
    void setA(int tmp) { A = tmp;}

    const std::vector<double>& getSides() const { return Sides;}
    void setSides(std::vector<double>& inputSides)
    {
        if (inputSides.size() != A)
        {
            std::cout << "Error sides.\n";
            return;
        }
        for (int i = 0; i < A; i++) Sides[i] = inputSides[i];
    }
};

class triangle : public Polygon
{
private:
    bool check(double a, double b, double c);
public:
    triangle() = delete;
    triangle(const std::vector<double>& tmp) : Polygon(3, tmp)
    {
        if (!check(tmp[0], tmp[1], tmp[2]))
        {
            std::cout << "Error triangle.\n";
            return;
        }
        std::cout << "Calling triangle.\n";
    }
    triangle(double a, double b, double c) : Polygon(3)
    {
        if (!check(a, b, c))
        {
            std::cout << "Error triangle.\n";
            return;
        }
        std::vector<double> tmp{ a, b, c };
        setSides(tmp);
        std::cout << "Calling triangle.\n";
    }
    virtual ~triangle(){}

    virtual double getPerimeter() const override final;
    virtual double getSquare() const override final;
    virtual void getInformation() const override final;
};

class Quadangle : public Polygon
{
protected:
    Quadangle() : Polygon(4)
    {
        std::cout << "Calling Quadangle.\n";
    }

public:
    Quadangle(const std::vector<double>& tmp) : Polygon(4, tmp)
    {
        std::cout << "Calling Quadangle.\n";
    }
    virtual ~Quadangle(){}

    virtual double getPerimeter() const = 0;
    virtual double getSquare() const = 0;
    virtual void getInformation() const = 0;
};

class rectangle : public Quadangle
{
private:
    double a, b;

public:
    rectangle() = delete;
    rectangle(double x, double y = 0) : a(x), b(y)
    {
        std::cout << "Calling Rectangle.\n";
    }
    virtual ~rectangle(){}

    virtual double getPerimeter() const override;
    virtual double getSquare() const override;
    virtual void getInformation() const override;
};

class Square : public rectangle
{
private:
    double a;

public:
    Square(double tmp) : a(tmp), rectangle(tmp)
    {
        std::cout << "Calling Square.\n";
    }
    virtual ~Square(){}

    virtual double getPerimeter() const override final;
    virtual double getSquare() const override final;
    virtual void getInformation() const override final;
};

#endif //UNTITLED8_FIGURES_H
