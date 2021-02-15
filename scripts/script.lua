function script(host)
	_createWindow(host, "engine", 600, 600, xpos, ypos, false)
	for i = 1,1000 do
		part = _addParticle(host, "engine")
		_setCoords(part, math.random(0, 600), math.random(0, 600))
		_setSpeed(part, math.random(-500, 500), math.random(-1000, 100))
		_setDirection(part, 1, 1)
	end
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
