#include "Enemy.h"
Enemy::Enemy()
{
    // Configurare corp (EnemyCircle)
    EnemyCircle.setRadius(20.f);
    EnemyCircle.setFillColor(Color(48, 87, 36));
    EnemyCircle.setOutlineColor(Color::Black);
    EnemyCircle.setOutlineThickness(2.f);
    EnemyCircle.setOrigin(Vector2f(20.f, 20.f));
    EnemyCircle.setPosition(Vector2f(500.f, 400.f)); // Poziție inițială (o poți modifica)

    // Configurare mână stângă (LeftHand)
    LeftHand.setSize(Vector2f(16.f, 6.f));  // Dimensiune mai mică decât arma
    LeftHand.setFillColor(Color(48, 87, 36)); // Aceeași culoare ca și corpul
    LeftHand.setOutlineColor(Color::Black);
    LeftHand.setOutlineThickness(2.f);
    LeftHand.setOrigin(Vector2f(8.f, 3.f)); // Centrare aproximativă
    LeftHand.setPosition(EnemyCircle.getPosition() + Vector2f(-18.f, 10.f)); // Lângă corp, spre stânga

    // Configurare mână dreaptă (RightHand)
    RightHand.setSize(Vector2f(16.f, 6.f));
    RightHand.setFillColor(Color(48, 87, 36));
    RightHand.setOutlineColor(Color::Black);
    RightHand.setOutlineThickness(2.f);
    RightHand.setOrigin(Vector2f(8.f, 3.f));
    RightHand.setPosition(EnemyCircle.getPosition() + Vector2f(18.f, 10.f)); // Lângă corp, spre dreapta

    health = 50;
    speed = 1.0f;
    angle = 0.0f;
}
void Enemy::Draw(RenderWindow& window)
{
    window.draw(RightHand);
    window.draw(LeftHand);
    window.draw(EnemyCircle);
}
void Enemy::TakeDamage(float value)
{
    health -= value;
    EnemyCircle.setFillColor(Color(139, 0, 0));
    RightHand.setFillColor(Color(139, 0, 0));
    LeftHand.setFillColor(Color(139, 0, 0));

    takesDamage = true;
    damageClock.restart();

    if (health < 0)
    {
        health = 0;
    }
    if (health == 0)
    {
        Die();
    }
}
void Enemy::Die()
{
    EnemyCircle.setFillColor(Color::Transparent);
    EnemyCircle.setOutlineColor(Color::Transparent);
    RightHand.setFillColor(Color::Transparent);
    RightHand.setOutlineColor(Color::Transparent);
    LeftHand.setFillColor(Color::Transparent);
    LeftHand.setOutlineColor(Color::Transparent);
    isDead = true;
}
void Enemy::Update(Player &player)
{
    if (!isDead && takesDamage && damageClock.getElapsedTime().asSeconds() >= 0.5f)
    {
        EnemyCircle.setFillColor(Color(48, 87, 36));
        RightHand.setFillColor(Color(48, 87, 36));
        LeftHand.setFillColor(Color(48, 87, 36));
        takesDamage = false;
    }
    Move(player);
}

void Enemy::Move(Player& player)
{
    Vector2f direction = player.getPlayerPosition() - EnemyCircle.getPosition();
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
    {
        direction /= length;
    }
    angle = atan2(direction.y, direction.x)*180/3.14159265;
    EnemyCircle.setRotation(degrees(angle));
 
    float radians = angle * 3.14159265 / 180.f;

    // Offset lateral pentru poziția brațelor (le păstrăm simetrice)
    Vector2f lateralOffset(sin(radians) * 20.f, -cos(radians) * 20.f);

    // **Mută brațele în față spre Player**
    Vector2f forwardOffset(direction * 10.f);  // Împinge brațele în față

    // Poziționează brațele
    LeftHand.setPosition(EnemyCircle.getPosition() - lateralOffset + forwardOffset);
    RightHand.setPosition(EnemyCircle.getPosition() + lateralOffset + forwardOffset);
    LeftHand.setRotation(degrees(angle));
    RightHand.setRotation(degrees(angle));
    EnemyCircle.move(direction * speed);
    LeftHand.move(direction * speed);
    RightHand.move(direction * speed);
}
bool Enemy::GetState()
{
    return isDead;
}
bool Enemy::Collides(Bullet& bullet) {
    float distance = sqrt(pow(bullet.GetPosition().x - EnemyCircle.getPosition().x, 2) +
        pow(bullet.GetPosition().y - EnemyCircle.getPosition().y, 2));
    return distance < (bullet.GetRadius() + EnemyCircle.getRadius());
}