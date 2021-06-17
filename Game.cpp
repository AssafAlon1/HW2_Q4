#include "Game.h"
#include "Exceptions.h"
#include "Sniper.h"
#include <algorithm>

namespace mtm
{
    Game::Game(int height, int width) : board(Board(height, width))
    {
    }


    // Move a character from source coordinates to destination coordinates according to the game's rules
    void Game::move (const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        // Verify basic board related situations
        if (!board.isCellInBoard(dst_coordinates))
        {
            throw IllegalCell();
        }

        if (!(board.isCellOccupied(src_coordinates)))
        {
            throw CellEmpty();
        }

        // Call the character's move function to continue the verification and do the moving
        board.getCharacter(src_coordinates)->move(board, src_coordinates, dst_coordinates);
    }


    std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team,
                                            units_t health, units_t ammo, units_t range, units_t power)
    {
        if (type == SNIPER)
        {
            return std::shared_ptr<Sniper>(new Sniper(health, ammo, range, power, team));
        }

        if (type == MEDIC)
        {
            return nullptr; // UPDATE ME
        }

        return nullptr; // UPDATE ME , SOLDIER
    }


    void Game::addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character)
    {
        if (!(board.isCellInBoard(coordinates)))
        {
            throw IllegalCell();
        }
        if (board.isCellOccupied(coordinates))
        {
            throw CellOccupied();
        }
        board.putCharacter(coordinates, character);
    }


    void Game::attack (const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        this->verifySourceCell(src_coordinates);

        // ??? Call attack functions

        return;
    }

    void Game::reload (const GridPoint& coordinates)
    {
        this->verifySourceCell(coordinates);
        this->board.getCharacter(coordinates)->reload();
    }

    bool Game::isOver (Team* winningTeam) const
    {
        int amount_of_powerlifters = 0;
        int amount_of_crossfitters = 0;
        for (Board::Iterator iterator = board.begin() ; !(iterator == board.end()) ; iterator++)
        {
            // No character in cell
            if ((*iterator) == nullptr)
            {
                continue;
            }

            // Powerlifter in cell
            if ( (*iterator)->getTeam() == POWERLIFTERS)
            {
                amount_of_powerlifters++;
                continue;
            }

            // Crossfitter in cell
            amount_of_crossfitters++;
        }

        if ((amount_of_crossfitters >  0 && amount_of_powerlifters >  0) || 
             (amount_of_crossfitters == 0 && amount_of_powerlifters == 0))
        {
            return false;
        }
        
        if (winningTeam != nullptr)
        {
            *winningTeam = amount_of_crossfitters == 0 ? POWERLIFTERS : CROSSFITTERS;
        }
        return true;
    }


    void Game::verifySourceCell(const GridPoint& coordinates)
    {
        if (!(this->board.isCellInBoard(coordinates)))
        {
            throw IllegalCell();
        }

        if (!(this->board.isCellOccupied(coordinates)))
        {
            throw CellEmpty();
        }
    }
}