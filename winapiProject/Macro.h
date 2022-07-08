#pragma once

#define SAFEDELETE(name) if(name){delete name; name = nullptr;}