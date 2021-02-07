#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,bool enemy) {

	this->imageCount = imageCount;
	this->switchTime = switchTime;
	this->enemy = enemy;

	totalTime = 0.0f;
	currentImage.x = 0;
	currentImage.y = 0;

	if (enemy == false) {
		uvRect.width = texture->getSize().x / float(imageCount.x);
		uvRect.height = texture->getSize().y / float(imageCount.y);

	}

	if (enemy == true)
	{
		uvRect.width = texture->getSize().x / float(imageCount.x);
		uvRect.height = texture->getSize().y / float(imageCount.y);
		

	}
	


}

Animation::~Animation() {



}

void Animation::Update(int row, float deltaTime, bool isLeft, bool enemy)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime ) {
	
		totalTime -= switchTime;
		currentImage.x++;
		if (enemy == false) {
			if (currentImage.x >= imageCount.x - 2 && currentImage.y == 0) {

				currentImage.x = 0;
			}


			if (currentImage.x >= imageCount.x -1 && currentImage.y == 1) {

				currentImage.x = 0;
			}

			if (currentImage.x >= imageCount.x - 1 && currentImage.y == 2) {

				currentImage.x = 0;
			}

			

		}else
			if (currentImage.x >= imageCount.x  && currentImage.y == 0) {

				currentImage.x = 0;
			}
		

	}

	


	//uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;

	if (isLeft) {
	
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	
	}
	else {
	
		uvRect.left = (currentImage.x+1)  * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
		
		

	}

}
