function script(host)
	_createWindow(host, "Test", 600, 600, xpos, ypos, false)
	for i = 1,10 do
		_addParticle(host, 300 + math.random(0, 20), math.random(0, 20), 300, math.random(10, 300), 1, 1)
	end
    _drawCircle(host, 300, 300, 50)
end

local center_x = 300
local center_y = 300

function update(particle)
	x, y = _getCoords(particle)
	dir_x, dir_y = _getDirection(particle)
	speed_x, speed_y = _getSpeed(particle)

	speed_x = speed_x + (center_x - x) * _getDelta()
	speed_y = speed_y + (center_y - y) * _getDelta()

	_setDirection(particle, dir_x, dir_y)
	_setSpeed(particle, speed_x, speed_y)
end
