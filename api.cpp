
#include "api.h"
#include "figures.h"
#include "writefile.h"
#include "randomization.h"

// Функкция генерации Count фигур типа Type
void CreateSameTypesShapes(int Count, ShapeType Type)
{
    vector <Point> Points;
    vector <vector <Point>> Figures;
    string json;
    string csv;
    Figure* Cyl = new Cylinder(0, 0);
    Figure* Sph = new Sphere(0);
    Figure* Surface = new Plane(0);
    switch (Type)
    {
    case ShapeType::Cylinder:
        for (int i = 0; i < Count; i++)
        {
            Figure* Cyl = new Cylinder(GetRandIntNumb(10, 100), GetRandIntNumb(10, 100));
            Points = Cyl->GetAsPoints(0);
            Figures.push_back(Points);
            delete Cyl;
        }
        csv += Cyl->GetAsCSV(Figures);
        break;
    case ShapeType::Sphere:
        for (int i = 0; i < Count; i++)
        {
            Figure* Sph = new Sphere(GetRandIntNumb(10, 100));
            Points = Sph->GetAsPoints(0);
            Figures.push_back(Points);

            delete Sph;
        }
        csv += Sph->GetAsCSV(Figures);
        break;
    case ShapeType::Surface:
        for (int i = 0; i < Count; i++)
        {
            Figure* Surface = new Plane(GetRandIntNumb(5000, 10000));
            Points = Surface->GetAsPoints(0);
            Figures.push_back(Points);
            delete Surface;
        }
        csv += Surface->GetAsCSV(Figures);
        break;
    }
    WriteInCSV(csv);
}

// Функция генерации Count фигур рандомного типа
void CreateRandTypesShapes(int Count)
{
    vector <Point> Points;
    vector <vector <Point>> Figures;
    string json;
    string csv;
    int hlp = 0;
    Figure* Cyl = new Cylinder(0, 0);
    Figure* Sph = new Sphere(0);
    Figure* Surface = new Plane(0);
    for (int i = 0; i < Count; i++)
    {
        hlp = GetRandIntNumb(1, 3);
        switch (hlp)
        {
        case 1:
            Cyl = new Cylinder(GetRandIntNumb(10, 100), GetRandIntNumb(10, 100));
            Points = Cyl->GetAsPoints(0);
            Figures.push_back(Points);
            csv += Cyl->GetAsCSV(Points);
            delete Cyl;
        break;
        case 2:
            Sph = new Sphere(GetRandIntNumb(10, 100));
            Points = Sph->GetAsPoints(0);
            Figures.push_back(Points);
            csv += Sph->GetAsCSV(Points);
            delete Sph;
        break;
        case 3:
            Surface = new Plane(GetRandIntNumb(5000, 10000));
            Points = Surface->GetAsPoints(0);
            Figures.push_back(Points);
            csv += Surface->GetAsCSV(Points);
            delete Surface;
        break;
        }
    }
    WriteInCSV(csv);
}