function script(host)
	_createWindow(host, "Test", 600, 600, xpos, ypos, false)
	for i = 1,50 do
		_addParticle(host, math.random(0, 600), math.random(0,600), 100, 100, 1, 1)
	end
end

function update(particle)
	x, y = _getCoords(particle)
	dir_x, dir_y = _getDirection(particle)
	if y > 600 or y < 0 then
		dir_y = dir_y * -1
	end
	if x > 600 or x < 0 then
		dir_x = dir_x * -1
	end
	_setDirection(particle, dir_x, dir_y)
end
