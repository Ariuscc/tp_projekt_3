#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];

/*
    SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0x00, 0x00, 0xFF);
    filledCircleColor(gRenderer.get(), q_x, q_y, 30, 0xFF0000FF);
*/
    
    SDL_Rect fillRect = {q_x,q_y,300,25};
    SDL_SetRenderDrawColor( gRenderer.get(),230,230,250,255);
    SDL_RenderFillRect( gRenderer.get(), &fillRect );
    
    SDL_Rect fillRect1 = {q_x,q_y-15,30,25};
    SDL_SetRenderDrawColor( gRenderer.get(),255,20,147,255);
    SDL_RenderFillRect( gRenderer.get(), &fillRect1 );        
    
    SDL_Rect fillRect2 = {q_x+270,q_y-15,30,25};
    SDL_SetRenderDrawColor( gRenderer.get(),255,20,147,255);
    SDL_RenderFillRect( gRenderer.get(), &fillRect2 );

}