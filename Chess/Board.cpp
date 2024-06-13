#include "Board.h"
#include "SFML/Graphics.hpp"
#include "Piece.h"
#include <iostream>

Board::Board()
{
	texture.loadFromFile(boardPath);
	sprite.setTexture(texture);

	possibleMoveOverlay.setSize(sf::Vector2f(100, 100));
	possibleMoveOverlay.setFillColor(sf::Color(0, 255, 0, 50)); // last arg - transparency 0-255

	captureMoveOverlay.setFillColor(sf::Color(255, 0, 0, 50));
	captureMoveOverlay.setSize(sf::Vector2f(100, 100));

}
Piece* Board::getPiece(field_t field)
{
	if (field.row > 7 || field.col > 7 || field.row < 0 || field.col < 0)
		return nullptr;
	return fields[field.row][field.col];
}
Piece* Board::getPiece(int row, int col)
{
	if (row > 7 || col > 7 || row < 0 || col < 0)
		return nullptr;
	return fields[row][col];
}
void Board::setPiece(Piece* piece, field_t field)
{
	if (field.row > 7 || field.col > 7 || field.row < 0 || field.col < 0)
		return;
	(*this).fields[field.row][field.col] = piece;
}


