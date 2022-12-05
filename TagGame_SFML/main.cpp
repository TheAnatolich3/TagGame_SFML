#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(256, 256), "TagGame");

	// �������� � �������� ��������
	Texture texture;
	texture.loadFromFile("Images/15.png");

	// ������ ������� ������ ����������� ����� ���������� 64 �������
	int blockWidht = 64;

	// ���������� ������������� �������� ����
	int grid[6][6] = { 0 };

	// ������ ��������
	Sprite sprite[17];


	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			n++;
			sprite[n].setTexture(texture);
			sprite[n].setTextureRect(IntRect(i * blockWidht, j * blockWidht, blockWidht, blockWidht));
			grid[i + 1][j + 1] = n;
		}
	}
	// ������� ���� ����������: �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
			{
				// ����� ��������� ���
				window.close();
			}

		}
		// ������������� ���� ���� - �����
		window.clear(Color::White);

		// ��������� ������� ������� �� ���� ����� + ��������� �������
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				// ��������� �������� ������ �������� �����
				int n = grid[i + 1][j + 1];
				// �� ������������� �� ��� ��������������� ������
				sprite[n].setPosition(i * blockWidht, j * blockWidht);
				// ��������� �������
				window.draw(sprite[n]);
			}
		}
		// ��������� ����
		window.display();
	}

	return 0;
}