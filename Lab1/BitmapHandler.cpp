#include "BitmapHandler.h"
sf::Image BitmapHandler::create(int width, int height)
{

	sf::Image image = sf::Image();

	image.create(width, height, sf::Color::Transparent);

	return image;
}
void BitmapHandler::save(sf::Image& imgae, std::string path)
{
	imgae.saveToFile(path);
}



sf::Image BitmapHandler::getImageFromFile(std::string path)
{

	sf::Texture texture;

	texture.loadFromFile(path);

	return texture.copyToImage();
}

void BitmapHandler::copyTo(sf::Image& image, sf::Image& to, int x, int y)
{
	to.copy(image, x, y);
}
