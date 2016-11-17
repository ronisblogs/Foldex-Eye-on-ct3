connection protocol:


Login:
	(LoginPage.qml)
	client:
		POST	/v1/login
		{	username: username.text,
			password: password.text
		}

	server:
		401	用户名或密码错误
		500	服务暂时不可用
		
		200

		{	"token": token,
			"vms": {
				"id1": {
					"name": name,
					"ip": ip,
					"os": os
				},
				"id2": {
				},
			}
		}
		

Connection working:
	
	Heartbeat:
		client:	/v1/heartbeat

		server: 
			200

	Connecting:
		client:	/v1/conn
			{ 'token': token, 'vm_id': vm_id }

		server:
			rdp protocol: {"rdp_ip":"","rdp_port":"","policy":""}
			spice protocol: {"vm_ip":"","vm_port":""}
