#include "TickTimer.h"
#include "Globals.h"

void Lilac::Utils::TickTimer::start()
{
    this->started = true;
    this->paused = false;
    this->start_ticks = SDL_GetTicks();
    this->paused_ticks = 0;
}

void Lilac::Utils::TickTimer::stop()
{
    this->started = false;
    this->paused = false;
    this->start_ticks = 0;
    this->paused_ticks = 0;
}

void Lilac::Utils::TickTimer::pause()
{
    if (this->started && !this->paused)
    {
        this->paused = true;
        this->paused_ticks = SDL_GetTicks() - this->start_ticks;
        this->start_ticks = 0;
    }
}

void Lilac::Utils::TickTimer::unpause()
{
    if (this->started && this->paused)
    {
        this->paused = false;
        this->start_ticks = SDL_GetTicks() - this->paused_ticks;
        this->paused_ticks = 0;
    }
}

Uint32 Lilac::Utils::TickTimer::get_ticks()
{
    Uint32 time = 0;

    if (this->started)
    {
        if (this->paused)
        {
            time = this->paused_ticks;
        }
        else
        {
            time = SDL_GetTicks() - this->start_ticks;
        }
    }

    return time;
}

bool Lilac::Utils::TickTimer::is_started()
{
	return this->started;
}

bool Lilac::Utils::TickTimer::is_paused()
{
	return this->paused && this->started;
}
