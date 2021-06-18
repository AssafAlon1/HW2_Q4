#include "Game.h"
#include "Exceptions.h"
#include "Sniper.h"
#include "Medic.h"
#include "Soldier.h"
#include <algorithm>
#include <type_traits>
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
        this->verifySourceCell(src_coordinates);

        // Call the character's move function to continue the verification and do the moving
        board.getCharacter(src_coordinates)->move(board, src_coordinates, dst_coordinates);
    }


    std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team,
                                            units_t health, units_t ammo, units_t range, units_t power)
    {
        if (health <= 0)
        {
            throw IllegalArgument();
        }

        if (type == SNIPER)
        {
            return std::shared_ptr<Sniper>(new Sniper(health, ammo, range, power, team));
        }

        if (type == MEDIC)
        {
            return std::shared_ptr<Medic>(new Medic(health, ammo, range, power, team));
        }

        return std::shared_ptr<Soldier>(new Soldier(health, ammo, range, power, team));
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
        // Verify source and destination cells are valid
        if (!board.isCellInBoard(dst_coordinates))
        {
            throw IllegalCell();
        }

        this->verifySourceCell(src_coordinates);
        
        this->board.getCharacter(src_coordinates)->attack(board , src_coordinates , dst_coordinates);
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

        // If both / none of the teams got living characters
        if ((amount_of_crossfitters >  0 && amount_of_powerlifters >  0) || 
             (amount_of_crossfitters == 0 && amount_of_powerlifters == 0))
        {
            return false;
        }
        
        // Update 
        if (winningTeam != nullptr)
        {
            *winningTeam = amount_of_crossfitters == 0 ? POWERLIFTERS : CROSSFITTERS;
        }
        return true;
    }


    std::ostream& operator<<(std::ostream& out_stream, const Game& game)
    {
        std::string board_representation_by_chars = "";
        for (Board::Iterator iterator = game.board.begin() ; !(iterator == game.board.end()) ; iterator++)
        {
            if (*iterator == nullptr)
            {
                board_representation_by_chars += " ";
                continue;
            }

            board_representation_by_chars += (*iterator)->getAscii();
        }

        // ????? IS UNSIGNED INT CASTING NEEDED??
        const char* str_end = board_representation_by_chars.c_str() + board_representation_by_chars.size();
        //int width_int = game.board.getWidth();
        //unsigned int width = static_cast<std::make_unsigned<decltype(width_int)>::type>(width_int);
        return printGameBoard(out_stream, board_representation_by_chars.c_str(), str_end, game.board.getWidth());
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