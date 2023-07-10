#include "World.h"

void World::drawRectWall(SDL_Renderer *renderer, int x, int y)
{
    SDL_SetRenderDrawColor (renderer, 255, 95, 31, 255); // Naranja neon
    SDL_Rect wall;
    wall.x = x;
    wall.y = y;
    wall.w = pixelSize;
    wall.h = pixelSize;

    SDL_RenderFillRect (renderer, &wall);

}
void World::drawRectTree(SDL_Renderer *renderer, int x, int y)
{
    SDL_SetRenderDrawColor (renderer, 95, 255, 31, 255); // Verde
    SDL_Rect tree;
    tree.x = x;
    tree.y = y;
    tree.w = pixelSize;
    tree.h = pixelSize;

    SDL_RenderFillRect (renderer, &tree);

}

void World::drawWorld(SDL_Renderer* renderer, const std::vector<std::string>& worldData)
{
    for (int row = 0; row < worldData.size(); ++row)
    {
        for (int col = 0; col < worldData[row].length(); ++col)
        {
            if (worldData[row][col] == '0')
            {
                int x = col * pixelSize;
                int y = row * pixelSize;
                drawRectWall(renderer, x, y);
            }
            else if(worldData[row][col] == 'A')
            {
                int x = col * pixelSize;
                int y = row * pixelSize;
                drawRectTree(renderer, x, y);
            }
        }
    }
}
void World::readWorld_txt()
{
    std::ifstream file("src/map.txt");
    std::string line;
    while (std::getline(file, line))
    {
        worldData.push_back(line);
    }
    file.close();
}