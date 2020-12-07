function script(host)
	_createWindow(host, "Test", 600, 600, xpos, ypos, false)
	for i = 1,50 do
		_addParticle(host, math.random(0, 600), math.random(0,600))
	end
end
