
enum class ShapeType {Cylinder, Sphere, Surface};

"@javadoc"
void CreateShapes(int Count, ShapeType Type); // Функкция генерации Count фигур типа Type
void CreateRandomShapes(int Count); // Функция генерации Count фигур рандомного типа

// Добавить в параметры управление типом файла и именем файла.
// Задокументировать все исключения
// Добавить управление разбиением на точки