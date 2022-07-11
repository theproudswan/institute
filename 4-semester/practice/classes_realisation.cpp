
#include "classes_declaration.h"


/*
*   Класс:          Location
*   Описание:       Абстрактное положение в пространстве без возможности отображения
*   Наследован от:  -
*/

Location::Location() {};
Location::Location(const int new_x, const int new_y) {
    x = new_x;
    y = new_y;
}
Location::~Location() {};
int Location::GetX() const {
    return x;
}
int Location::GetY() const {
    return y;
}
void Location::SetX(const int new_x) {
    x = new_x;
}
void Location::SetY(const int new_y) {
    y = new_y;
}
void Location::SetPos(const int new_x, const int new_y) {
    x = new_x;
    y = new_y;
}
void Location::SetPos(const POINT new_location) {
    x = new_location.x;
    y = new_location.y;
}

POINT Location::GetLocation() const {
    return POINT({ GetX(), GetY() });
}

/*
*   ============ Конец определения класса Location ============
*/

/*
*   Класс:          Point
*   Описание:       Точка в пространстве. Один пиксель, к которому привязываются более сложные объекты
*   Наследован от:  Location
*/

Point::Point() {};
Point::Point(const Location& location) : Location(location) {
    x = location.GetX();
    y = location.GetY();
}
Point::Point(const int new_x, const int new_y) : Location(new_x, new_y) {
    x = new_x;
    y = new_y;
}
Point::~Point() {};

COLORREF Point::GetColor() const {
    return color;
}
void Point::SetColor(COLORREF new_color) {
    color = new_color;
}

void Point::Show() {
    visibility = true;
    HBRUSH brush = CreateSolidBrush(color);
    SelectObject(hdc, brush);
    SetPixel(hdc, x, y, color);
    DeleteObject(brush);
}
void Point::Hide() {
    visibility = false;
    HBRUSH brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    SetPixel(hdc, x, y, BACKGROUND_COLOR);
    DeleteObject(brush);
}
void Point::MoveTo(const int new_x, const int new_y) {
    Hide();
    SetX(new_x);
    SetY(new_y);
    Show();
}
bool Point::IsVisible() const {
    return visibility;
}

/*
*   ============ Конец определения класса Point ============
*/

/*
*   Класс:          Food
*   Описание:       Еда Пакмана в виде оранжевых точек
*   Наследован от:  Point
*/

Food::Food() {
    color = RGB(247, 105, 22);
};
Food::Food(const int new_x, const int new_y) : Point(new_x, new_y) {
    x = new_x;
    y = new_y;
    color = RGB(247, 105, 22);
}
Food::~Food() {};

int Food::GetRadius() const {
    return radius;
}
void Food::SetRadius(const int new_radius) {
    radius = new_radius;
}
int Food::GetTypeId() const {
    return type_id;
}

void Food::Show() {
    visibility = true;
    HBRUSH brush = CreateSolidBrush(color);
    SelectObject(hdc, brush);
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
    DeleteObject(brush);
}
void Food::Hide() {
    visibility = false;
    HBRUSH brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
    DeleteObject(brush);
}

bool Food::operator==(const Food& rhs)
{
    return (this->GetX() == rhs.GetX()) && (this->GetY() == rhs.GetY());
}
/*
*   ============ Конец определения класса Food ============
*/



/*
*   Класс:          ImmortalFood
*   Описание:       Еда в виде вишенки делает пакмана неуязвимым для приведений
*   Наследован от:  Food
*/
ImmortalFood::ImmortalFood() {
    color = RGB(179, 12, 12);
};
ImmortalFood::ImmortalFood(const int new_x, const int new_y) : Food(new_x, new_y) {
    x = new_x;
    y = new_y;
    color = RGB(179, 12, 12);
}
ImmortalFood::~ImmortalFood() {};

int ImmortalFood::GetTypeId() const {
    return type_id;
}

void ImmortalFood::Show() {
    visibility = true;
    HBRUSH brush = CreateSolidBrush(color);
    SelectObject(hdc, brush);
    Ellipse(hdc, x - radius * 2, y - radius, x, y + radius);
    Ellipse(hdc, x, y - radius, x + radius * 2, y + radius);
    DeleteObject(brush);
    brush = CreateSolidBrush(RGB(13, 168, 19));
    SelectObject(hdc, brush);
    Ellipse(hdc, x - radius, y - radius, x + radius, y);
    DeleteObject(brush);
}
void ImmortalFood::Hide() {
    visibility = false;
    HBRUSH brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    Ellipse(hdc, x - radius * 2, y - radius, x - radius, y + radius);
    Ellipse(hdc, x + radius * 2, y - radius, x + radius, y + radius);
    Ellipse(hdc, x - radius, y - radius, x + radius, y);
    DeleteObject(brush);
}

/*
*   ============ Конец определения класса ImmortalFood ============
*/

/*
*   Класс:          Pacman
*   Описание:       Классический Pacman
*   Наследован от:  Point
*/

Pacman::Pacman() {
    color = RGB(245, 185, 34);
};
Pacman::Pacman(const int new_x, const int new_y) : Point(new_x, new_y) {
    x = new_x;
    y = new_y;
    color = RGB(245, 185, 34);
}
Pacman::~Pacman() {};

int Pacman::GetRadius() const {
    return radius;
}
void Pacman::SetRadius(const int new_radius) {
    radius = new_radius;
}

bool Pacman::Touch(const int AnotherObjX, const int AnotherObjY) const { // Узнать о столкновении
    // Столкновение вычисляется по формуле:
    // (x - x0)^2 + (y - y0)^2 <= R^2
    // 
    // x  - координаты другого объекта Х
    // х0 - координаты метеорита по Х
    // у  - координаты другого объекта У
    // у0 - координаты метеорита по У
    // R  - радиус метеорита

    // Если формула выше истинна, вернуть true, иначе - false
    if (pow(AnotherObjX - x, 2) + pow(AnotherObjY - y, 2) <= pow(radius, 2)) return true;
    return false;
} // Конец Touch()
bool Pacman::Touch(const POINT AnotherObj) const { // Узнать о столкновении
    // Столкновение вычисляется по формуле:
    // (x - x0)^2 + (y - y0)^2 <= R^2
    // 
    // x  - координаты другого объекта Х
    // х0 - координаты метеорита по Х
    // у  - координаты другого объекта У
    // у0 - координаты метеорита по У
    // R  - радиус метеорита

    // Если формула выше истинна, вернуть true, иначе - false
    if (pow(AnotherObj.x - x, 2) + pow(AnotherObj.y - y, 2) <= pow(radius, 2)) return true;
    return false;
} // Конец Touch()

void Pacman::Show() {
    visibility = true;
    HBRUSH brush = CreateSolidBrush(color);
    SelectObject(hdc, brush);
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
    DeleteObject(brush);
    brush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, brush);
    Ellipse(hdc, eye_coord.x - eye_radius, eye_coord.y + eye_radius, eye_coord.x + eye_radius, eye_coord.y - eye_radius);
    DeleteObject(brush);
    brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    if (!openning_mouth) {
        delta_mouth--;
    }
    else {
        delta_mouth++;
    }
    Polygon(hdc, mouth, 3);
    DeleteObject(brush);
    if (delta_mouth >= 15) {
        openning_mouth = false;
    }
    if (delta_mouth <= 0) {
        openning_mouth = true;
    }
}
void Pacman::Won() {
    HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
    SelectObject(hdc, brush);
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
    DeleteObject(brush);
    brush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, brush);
    Ellipse(hdc, eye_coord.x - eye_radius, eye_coord.y + eye_radius, eye_coord.x + eye_radius, eye_coord.y - eye_radius);
    DeleteObject(brush);
    brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    if (!openning_mouth) {
        delta_mouth--;
    }
    else {
        delta_mouth++;
    }
    Polygon(hdc, mouth, 3);
    DeleteObject(brush);
    if (delta_mouth >= 15) {
        openning_mouth = false;
    }
    if (delta_mouth <= 0) {
        openning_mouth = true;
    }
}
void Pacman::Hide() {
    visibility = false;
    HBRUSH brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
    DeleteObject(brush);
}
void Pacman::Die() {
    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, brush);
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
    DeleteObject(brush);
    brush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, brush);
    Ellipse(hdc, eye_coord.x - eye_radius, eye_coord.y + eye_radius, eye_coord.x + eye_radius, eye_coord.y - eye_radius);
    DeleteObject(brush);
    brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    if (!openning_mouth) {
        delta_mouth--;
    }
    else {
        delta_mouth++;
    }
    Polygon(hdc, mouth, 3);
    DeleteObject(brush);
    if (delta_mouth >= 15) {
        openning_mouth = false;
    }
    if (delta_mouth <= 0) {
        openning_mouth = true;
    }
    PlaySound(TEXT("pacman_death.wav"), NULL, SND_FILENAME | SND_ASYNC);
    Sleep(1500);
}

void Pacman::TurnUp() {
    eye_coord = { x - 10, y };

    mouth[0] = { x, y + 5 };
    mouth[1] = { x - delta_mouth, y - radius - 5 };
    mouth[2] = { x + delta_mouth, y - radius - 5 };
}
void Pacman::TurnDown() {
    eye_coord = { x + 10, y };

    mouth[0] = { x, y - 5 };
    mouth[1] = { x - delta_mouth, y + radius + 5 };
    mouth[2] = { x + delta_mouth, y + radius + 5 };
}
void Pacman::TurnLeft() {
    eye_coord = { x, y - 10 };

    mouth[0] = { x + 5, y };
    mouth[1] = { x - radius - 5, y - delta_mouth };
    mouth[2] = { x - radius - 5, y + delta_mouth };
}
void Pacman::TurnRight() {
    eye_coord = { x, y - 10 };

    mouth[0] = { x - 5, y };
    mouth[1] = { x + radius + 5, y - delta_mouth };
    mouth[2] = { x + radius + 5, y + delta_mouth };
}

int Pacman::GetTypeId() const {
    return type_id;
}

/*
*   ============ Конец определения класса Pacman ============
*/

/*
*   Класс:          ImmortalPacman
*   Описание:       Неуязвимый для приведений Pacman
*   Наследован от:  Pacman
*/

ImmortalPacman::ImmortalPacman() {
    color = RGB(20, 8, 255);
};
ImmortalPacman::ImmortalPacman(const int new_x, const int new_y) : Pacman(new_x, new_y) {
    x = new_x;
    y = new_y;
    color = RGB(0, 8, 255);
}
ImmortalPacman::~ImmortalPacman() {}
int ImmortalPacman::GetTypeId() const {
    return type_id;
}
void ImmortalPacman::Show() {
    visibility = true;
    HBRUSH brush = CreateSolidBrush(color);
    SelectObject(hdc, brush);
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
    DeleteObject(brush);
    brush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, brush);
    Ellipse(hdc, eye_coord.x - eye_radius, eye_coord.y + eye_radius, eye_coord.x + eye_radius, eye_coord.y - eye_radius);
    DeleteObject(brush);
    brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    if (!openning_mouth) {
        delta_mouth--;
    }
    else {
        delta_mouth++;
    }

    Polygon(hdc, mouth, 3);
    DeleteObject(brush);
    if (delta_mouth >= 15) {
        openning_mouth = false;
    }
    if (delta_mouth <= 0) {
        openning_mouth = true;
    }
}
void ImmortalPacman::Hide() {
    Pacman::Hide();
}

/*
*   ============ Конец определения класса ImmortalPacman ============
*/

/*
*   Класс:          Cast
*   Описание:       Интерфейс класса приведения
*   Наследован от:  Point
*/

Cast::Cast(const int new_x, const int new_y) : Point(new_x, new_y) {
    x = new_x;
    y = new_y;
}
Cast::~Cast() {}

/*
*   ============ Конец определения класса Cast ============
*/

/*
*   Класс:          ClassicCast
*   Описание:       Одноцветное приведение, двигается горизонтально
*   Наследован от:  Cast
*/

ClassicCast::ClassicCast() {
    color = RGB(100 + rand() % 100, 100 + rand() % 100, 100 + rand() % 100);
}
ClassicCast::ClassicCast(const int new_x, const int new_y) : Cast(new_x, new_y) {
    x = new_x;
    y = new_y;
    color = RGB(100 + rand() % 100, 100 + rand() % 100, 100 + rand() % 100);
}
ClassicCast::~ClassicCast() {}
void ClassicCast::Body() {
    HBRUSH brush = CreateSolidBrush(color);
    SelectObject(hdc, brush);
    RoundRect(hdc, x, y, x + 50, y + 80, 40, 30);
    DeleteObject(brush);
    brush = CreateSolidBrush(TRANSPARENT);
    SelectObject(hdc, brush);
    Rectangle(hdc, x, y + 60, x + 50, y + 80);
    DeleteObject(brush);
}
void ClassicCast::Wawes() {
    HPEN pen = GetStockPen(NULL_PEN);
    HBRUSH brush = CreateSolidBrush(color);
    SelectPen(hdc, pen);
    SelectObject(hdc, brush);
    Ellipse(hdc, x + 0, y + 60 - 5, x + 10, y + 60 + 5);
    Ellipse(hdc, x + 20, y + 60 - 5, x + 30, y + 60 + 5);
    Ellipse(hdc, x + 40, y + 60 - 5, x + 50, y + 60 + 5);
    DeleteObject(brush);
    brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    Ellipse(hdc, x + 10, y + 60 - 5, x + 20, y + 60 + 5);
    Ellipse(hdc, x + 30, y + 60 - 5, x + 40, y + 60 + 5);
    DeleteObject(brush);
}
void ClassicCast::Eyes() {
    POINT left_eye = { x + 13, y + 18 };
    POINT right_eye = { x + 36, y + 18 };
    int pupil_rad = 3;

    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, brush);
    Ellipse(hdc, x + 7, y + 12, x + 20, y + 25);
    Ellipse(hdc, x + 50 - 7, y + 12, x + 50 - 20, y + 25);
    DeleteObject(brush);
    brush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, brush);
    Ellipse(hdc, left_eye.x - pupil_rad, left_eye.y - pupil_rad, left_eye.x + pupil_rad, left_eye.y + pupil_rad);
    Ellipse(hdc, right_eye.x - pupil_rad, right_eye.y - pupil_rad, right_eye.x + pupil_rad, right_eye.y + pupil_rad);
    DeleteObject(brush);
}

void ClassicCast::Show() {
    visibility = true;
    ClassicCast::Body();
    ClassicCast::Wawes();
    ClassicCast::Eyes();
}
void ClassicCast::Hide() {
    visibility = false;
    HBRUSH brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    RoundRect(hdc, x, y, x + 50, y + 80, 40, 30);
    DeleteObject(brush);
}
int ClassicCast::GetTypeId() const {
    return type_id;
}

/*
*   ============ Конец определения класса ClassicCast ============
*/

/*
*   Класс:          RainbowCast
*   Описание:       Приведение, меняющее цвет, двигается по вертикали
*   Наследован от:  Cast
*/

RainbowCast::RainbowCast() {
    color_r = 100 + rand() % 100;
    color_g = 100 + rand() % 100;
    color_b = 100 + rand() % 100;
    color = RGB(color_r, color_g, color_b);
}
RainbowCast::RainbowCast(const int new_x, const int new_y) : Cast(new_x, new_y) {
    x = new_x;
    y = new_y;
    color_r = 100 + rand() % 100;
    color_g = 100 + rand() % 100;
    color_b = 100 + rand() % 100;
    color = RGB(color_r, color_g, color_b);
}
RainbowCast::~RainbowCast() {}

int RainbowCast::GetTypeId() const {
    return type_id;
}

void RainbowCast::Body() {
    HBRUSH brush = CreateSolidBrush(color);
    SelectObject(hdc, brush);
    RoundRect(hdc, x, y, x + 50, y + 80, 40, 30);
    DeleteObject(brush);
    brush = CreateSolidBrush(TRANSPARENT);
    SelectObject(hdc, brush);
    Rectangle(hdc, x, y + 60, x + 50, y + 80);
    DeleteObject(brush);
}
void RainbowCast::Wawes() {
    HPEN pen = GetStockPen(NULL_PEN);
    HBRUSH brush = CreateSolidBrush(color);
    SelectPen(hdc, pen);
    SelectObject(hdc, brush);
    POINT poly1[] = { {x, y + 60}, {x + 5, y + 65}, {x + 10, y + 60} };
    POINT poly2[] = { {x + 20, y + 60}, {x + 20 + 5, y + 65}, {x + 30, y + 60} };
    POINT poly3[] = { {x + 40, y + 60}, {x + 40 + 5, y + 65}, {x + 50, y + 60} };

    Polygon(hdc, poly1, 3);
    Polygon(hdc, poly2, 3);
    Polygon(hdc, poly3, 3);

    DeleteObject(brush);
}
void RainbowCast::Eyes() {
    POINT left_eye = { x + 13, y + 18 };
    POINT right_eye = { x + 36, y + 18 };
    int pupil_rad = 3;

    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, brush);
    Ellipse(hdc, x + 7, y + 12, x + 20, y + 25);
    Ellipse(hdc, x + 50 - 7, y + 12, x + 50 - 20, y + 25);
    DeleteObject(brush);
    brush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, brush);
    Ellipse(hdc, left_eye.x - pupil_rad, left_eye.y - pupil_rad, left_eye.x + pupil_rad, left_eye.y + pupil_rad);
    Ellipse(hdc, right_eye.x - pupil_rad, right_eye.y - pupil_rad, right_eye.x + pupil_rad, right_eye.y + pupil_rad);
    DeleteObject(brush);
}

void RainbowCast::Show() {
    visibility = true;
    RainbowCast::Body();
    RainbowCast::Wawes();
    RainbowCast::Eyes();
}
void RainbowCast::Hide() {
    visibility = false;
    HBRUSH brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    RoundRect(hdc, x, y, x + 53, y + 80, 40, 30);
    DeleteObject(brush);

    // Updating color
    color_r += (rand() % 2 * 5) - (rand() % 2 * 5);
    color_g += (rand() % 2 * 5) - (rand() % 2 * 5);
    color_b += (rand() % 2 * 5) - (rand() % 2 * 5);
    color = RGB(color_r, color_g, color_b);
}

/*
*   ============ Конец определения класса RainbowCast ============
*/

/*
*   Класс:          Wall
*   Описание:       Представляет собой экземпляр стены
*   Наследован от:  Point
*/

Wall::Wall() {
    color = RGB(214, 157, 11);
};
Wall::Wall(int new_x_beg, int new_y_beg, int new_x_end, int new_y_end)
    : x_beg(new_x_beg), y_beg(new_y_beg), x_end(new_x_end), y_end(new_y_end) {
    color = RGB(214, 157, 11);
}
Wall::~Wall() {};

void Wall::Show() {
    visibility = true;
    HBRUSH brush = CreateSolidBrush(color);
    SelectObject(hdc, brush);
    RoundRect(hdc, x_beg, y_beg, x_end, y_end, 1, 1);
    DeleteObject(brush);
}
void Wall::Hide() {
    visibility = false;
    HBRUSH brush = CreateSolidBrush(BACKGROUND_COLOR);
    SelectObject(hdc, brush);
    RoundRect(hdc, x_beg, y_beg, x_end, y_end, 10, 10);
    DeleteObject(brush);
}
void Wall::ChangeParams(int new_x_beg, int new_y_beg, int new_x_end, int new_y_end) {
    x_beg = (new_x_beg), y_beg = (new_y_beg), x_end = (new_x_end), y_end = (new_y_end);
}
int Wall::GetXBeg() const { return x_beg; }
int Wall::GetYBeg() const { return y_beg; }
int Wall::GetXEnd() const { return x_end; }
int Wall::GetYEnd() const { return y_end; }

/*
*   ============ Конец определения класса Wall ============
*/

/*
*   Класс:          GameManager
*   Описание:       Средство управления игрой (генерация уровня, игровая механика)
*   Наследован от:  -
*/
void GameManager::MoveCast(Cast& cast, short& direction) {
    if (cast.GetTypeId() == 0) {
        if (points.find(POINT({ cast.GetX(), cast.GetY() })) == points.end()
            && points.find(POINT({ cast.GetX() + 50, cast.GetY() })) == points.end()) {
            if (direction) {
                cast.MoveTo(cast.GetX() + CASTS_SPEED, cast.GetY());
            }
            else {
                cast.MoveTo(cast.GetX() - CASTS_SPEED, cast.GetY());
            }
        }
        else {
            if (direction) {
                cast.MoveTo(cast.GetX() - CASTS_SPEED, cast.GetY());
            }
            else {
                cast.MoveTo(cast.GetX() + CASTS_SPEED, cast.GetY());
            }
            direction = !direction;
        }
    }
    if (cast.GetTypeId() == 1) {
        if (points.find(POINT({ cast.GetX(), cast.GetY() })) == points.end()
            && points.find(POINT({ cast.GetX(), cast.GetY() + 80 })) == points.end()) {
            if (direction) {
                cast.MoveTo(cast.GetX(), cast.GetY() + CASTS_SPEED);
            }
            else {
                cast.MoveTo(cast.GetX(), cast.GetY() - CASTS_SPEED);
            }
        }
        else {
            if (direction) {
                cast.MoveTo(cast.GetX(), cast.GetY() - CASTS_SPEED);
            }
            else {
                cast.MoveTo(cast.GetX(), cast.GetY() + CASTS_SPEED);
            }
            direction = !direction;
        }
    }
}
void GameManager::CreateFirstLevel() {
    system("cls");
    {
        walls.push_back(Wall(10, 0, 1900, 5));
        walls.push_back(Wall(10, 0, 15, 900));
        walls.push_back(Wall(10, 900, 1900, 905));
        walls.push_back(Wall(1895, 0, 1900, 905));
        //----------------------------------------
        walls.push_back(Wall(90, 90, 200, 200));
        //----------------------------------------
        walls.push_back(Wall(280, 90, 750, 95));
        walls.push_back(Wall(750, 90, 755, 395));
        walls.push_back(Wall(280, 190, 655, 195));
        walls.push_back(Wall(655, 195, 660, 395));
        //----------------------------------------
        walls.push_back(Wall(280, 390, 660, 395));
        walls.push_back(Wall(280, 260, 580, 325));

        walls.push_back(Wall(90, 270, 200, 600));

        walls.push_back(Wall(280, 460, 850, 465));
        walls.push_back(Wall(850, 0, 855, 395));
        walls.push_back(Wall(280, 460, 850, 465));
        //----------------------------------------
        walls.push_back(Wall(950, 105, 1800, 110));
        walls.push_back(Wall(1800, 110, 1795, 465));
        walls.push_back(Wall(950, 210, 1250, 465));
        walls.push_back(Wall(1350, 210, 1355, 465));
        walls.push_back(Wall(1455, 210, 1695, 465));
        //----------------------------------------
        walls.push_back(Wall(950, 565, 1800, 670));
        walls.push_back(Wall(280, 565, 850, 570));
        walls.push_back(Wall(280, 665, 850, 670));
        //----------------------------------------
        walls.push_back(Wall(950, 790, 1300, 785));
        walls.push_back(Wall(1400, 790, 1800, 785));
        walls.push_back(Wall(90, 805, 850, 800));

    }
    FindWallCoord();
    for (auto i : walls) {
        i.Show();
    }

    {
        casts.push_back(new ClassicCast(600, 110));
        casts.push_back(new ClassicCast(1825, 15));
        casts.push_back(new ClassicCast(1825, 815));
        casts.push_back(new ClassicCast(90, 700));
        casts.push_back(new RainbowCast(1270, 200));
        casts.push_back(new RainbowCast(1380, 400));
        casts.push_back(new RainbowCast(1720, 400));
    }
    for (int i = 0; i < casts.size(); i++) {
        casts[i]->Show();
        casts_direction.push_back(rand() % 2);
    }
    {
        for (int i = 45; i <= 870; i += 30) {
            food.insert(new Food(45, i));
        }
        for (int i = 75; i <= 1870; i += 30) {
            food.insert(new Food(i, 855));
        }
        for (int i = 825; i >= 30; i -= 30) {
            food.insert(new Food(1845, i));
        }
        for (int i = 1815; i >= 900; i -= 30) {
            food.insert(new Food(i, 45));
        }
        for (int i = 75; i <= 870; i += 30) {
            food.insert(new Food(915, i));
        }
        for (int i = 75; i <= 1840; i += 30) {
            food.insert(new Food(i, 730));
        }
        for (int i = 300; i <= 1840; i += 30) {
            food.insert(new Food(i, 530));
        }
        for (int i = 45; i <= 800; i += 30) {
            food.insert(new Food(i, 45));
        }
        for (int i = 75; i <= 400; i += 30) {
            food.insert(new Food(795, i));
        }
        for (int i = 75; i <= 710; i += 30) {
            food.insert(new Food(250, i));
        }
        for (int i = 300; i <= 870; i += 30) {
            food.insert(new Food(i, 620));
        }
        for (int i = 300; i <= 700; i += 30) {
            food.insert(new Food(i, 150));
        }
        for (int i = 180; i <= 410; i += 30) {
            food.insert(new Food(690, i));
        }
        for (int i = 220; i <= 380; i += 30) {
            food.insert(new Food(615, i));
        }
        for (int i = 930; i <= 1750; i += 30) {
            food.insert(new Food(i, 150));
        }

        food.insert(new ImmortalFood(150, 240));
        food.insert(new ImmortalFood(1720 + 25, 340));
        food.insert(new ImmortalFood(1270 + 25, 340));
        food.insert(new ImmortalFood(1380 + 25, 340));
    }
    for (auto i : food) {
        i->Show();
    }
    pacman = new Pacman(PACMAN_START_POS);
    pacman->Show();
    SetTextColor(hdc, 0x000000);
}

void GameManager::FindWallCoord() {
    for (auto i : walls) {
        int xb, yb, xe, ye;

        for (xb = min(i.GetXBeg(), i.GetXEnd())
            , xe = max(i.GetXBeg(), i.GetXEnd()); xb <= xe; xb++) {
            for (yb = min(i.GetYBeg(), i.GetYEnd())
                , ye = max(i.GetYBeg(), i.GetYEnd()); yb <= ye; yb++) {
                points.insert(POINT({ xb, yb }));
            }
        }
    }
}
void GameManager::Play() {

    while (PACMAN_DOESNT_TOUCH_WALL) {

        string score_str = "Score: " + to_string(score);
        SelectObject(hdc, hfont);
        TextOutA(hdc, 900, 940, score_str.c_str(), score_str.size());
        int eaten_food_id = PacmanEatFood();
        if (eaten_food_id >= 0) {
            auto get_prev_pos = pacman->GetLocation();
            pacman = pacman_transition[pacman->GetTypeId()][eaten_food_id];
            pacman->SetPos(get_prev_pos);
            score++;
        }
        if (KEY_DOWN(37)) {	// Стрелка влево  
            pacman->TurnLeft();
            pacman->MoveTo(pacman->GetX() - 1, pacman->GetY());
        }
        if (KEY_DOWN(38)) { // Стрелка вверх
            pacman->TurnUp();
            pacman->MoveTo(pacman->GetX(), pacman->GetY() - 1);
        }
        if (KEY_DOWN(39)) {   // Стрелка вправо
            pacman->TurnRight();
            pacman->MoveTo(pacman->GetX() + 1, pacman->GetY());
        }
        if (KEY_DOWN(40)) {	// Стрелка вниз     
            pacman->TurnDown();
            pacman->MoveTo(pacman->GetX(), pacman->GetY() + 1);
        }
        for (int i = 0; i < casts.size(); i++) {
            if (pacman->GetTypeId() == 1) {
                break;
            }
            if (pacman->Touch(casts[i]->GetX() + 25, casts[i]->GetY() + 40)) { // Относительно центра приведения
                pacman->Die();
                End();
                return;
            }
        }
        MoveAllCasts();
        for (auto i : food) {
            i->Show();
        }
        if (!food.size()) {
            pacman->Won();
        }
        Sleep(10);
    }
    pacman->Die();

    End();
}
void GameManager::End() {
    system("cls");
    cout << "Total score: " << score << endl;
    return;
}
void GameManager::MoveAllCasts() {
    for (int i = 0; i < casts.size(); i++) {
        MoveCast(*casts[i], casts_direction[i]);
    }
}
int GameManager::PacmanEatFood() {
    for (auto i : food) {
        if (pacman->Touch(i->GetX(), i->GetY())) {
            food.erase(i);
            if (i->GetTypeId() == 1) {
                PlaySound(TEXT("pacman_eatfruit.wav"), NULL, SND_FILENAME | SND_ASYNC);
                PlaySound(TEXT("pacman_intermission.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }
            else {
                PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            return i->GetTypeId();
        }
    }
    return -1;
}
/*
*   ============ Конец определения класса GameManager ============
*/

