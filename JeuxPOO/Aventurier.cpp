#include "Aventurier.h"
#include <locale>

using namespace std;

Aventurier::Aventurier(const Position& position, int pointDeVie, int pointDeForce, int bourseDePieces) :
    Personnage{ position,pointDeVie,pointDeForce }, d_bourseDePieces{ bourseDePieces }
{
    d_tabEquipement.push_back(std::make_unique<Armure>(100));

}


Aventurier::~Aventurier()
{
    //dtor
}

std::vector<std::unique_ptr<Equipement>> const& Aventurier::tabEquipement() const
{
    return d_tabEquipement;
}

void Aventurier::ajouterEquipement(unique_ptr<Equipement> e)
{
    d_tabEquipement.push_back(move(e));
}

void Aventurier::deplacer(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Up:
            this.deplacer(0, 1);
            break;
        case sf::Keyboard::Down:
            this.deplacer(0, -1);
            break;
        case sf::Keyboard::Left:
            this.deplacer(-1, 0);
            break;
        case sf::Keyboard::Right:
            this.deplacer(1, 0);
            break;

        default:
        }
    }

    void Aventurier::Attaquer(Monstre & M) {
        if ((M.d_position.x() - this.d_position.x() = 1) || (M.d_position.y() - this.d_position.y() = 1))
        {
            M.encaisser(this.d_pointDeForce)
        }
    }
}