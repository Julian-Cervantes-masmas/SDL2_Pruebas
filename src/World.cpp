#include "World.h"

void World::drawRectWall(SDL_Renderer *renderer, int x, int y)
{
    SDL_SetRenderDrawColor (renderer, 255, 95, 31, 255); // Naranja neon 255, 95, 31, 255)
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
void World::drawRectFloor(SDL_Renderer *renderer, int x, int y)
{
    SDL_SetRenderDrawColor (renderer, 95, 99, 82, 255); // Verde pasto
    SDL_Rect floor;
    floor.x = x;
    floor.y = y;
    floor.w = pixelSize;
    floor.h = pixelSize;

    SDL_RenderFillRect (renderer, &floor);
}
void World::drawRectRoad(SDL_Renderer *renderer, int x, int y)
{
    SDL_SetRenderDrawColor (renderer, 85, 89, 72, 255); // Road
    SDL_Rect road;
    road.x = x;
    road.y = y;
    road.w = pixelSize;
    road.h = pixelSize;

    SDL_RenderFillRect (renderer, &road);
}
void World::drawRectInterior(SDL_Renderer *renderer, int x, int y)
{
    SDL_SetRenderDrawColor(renderer, 65, 69, 52, 255); // Pisos de interior
    SDL_Rect interior;
    interior.x = x;
    interior.y = y;
    interior.w = pixelSize;
    interior.h = pixelSize;

    SDL_RenderFillRect (renderer, &interior);
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
            else if (worldData[row][col] == '*')
            {
                int x = col * pixelSize;
                int y = row * pixelSize;
                drawRectFloor(renderer, x, y);
            }
            else if (worldData[row][col] == '.')
            {
                int x = col * pixelSize;
                int y = row * pixelSize;
                drawRectRoad(renderer, x, y);
            }
            else if (worldData[row][col] == '_')
            {
                int x = col * pixelSize;
                int y = row * pixelSize;
                drawRectInterior(renderer, x, y);
            }
        }
    }
}
void World::readWorld_txt()
{
    std::ifstream file("src/assets/map.txt");
    std::string line;
    while (std::getline(file, line))
    {
        worldData.push_back(line);
    }
    file.close();
}

bool World::wallPosition(int x, int y) const
{
    int row = y / pixelSize;
    int col = x / pixelSize;

    if (row >= 0 && row < worldData.size() && col >= 0 && col < worldData[row].length())
    {
        return worldData[row][col] == '0';
    }
    return false;

}