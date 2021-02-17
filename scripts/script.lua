function init(host)
	_createWindow(host, "engine", 600, 600, xpos, ypos, false)
	for i = 1, 10000 do
		part = _addParticle(host, "engine")
		_setCoords(part, math.random(0, 600), math.random(0, 600))
		_setSpeed(part, math.random(0, 365), math.random(1, 300))
		_setDirection(part, 0, 0)
		_setColor(part, math.random(50, 255), math.random(50, 255), math.random(50, 255), 0)
	end
end

function update(host, particle)
	x, y = _getCoords(particle)
	center_x, center_y = _getCenterCoords(host, "engine")
	angle, radius = _getSpeed(particle)

	angle = angle + radius / 10000
	x = center_x + math.cos(angle) * radius 
	y = center_y + math.sin(angle) * radius

	_setSpeed(particle, angle, radius)
	_setCoords(particle, x, y)

end
