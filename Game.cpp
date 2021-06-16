#include "Game.h"
#include "Exceptions.h"
#include "Sniper.h"

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

        if (board.isCellOccupied(src_coordinates))
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
}