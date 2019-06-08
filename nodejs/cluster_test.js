var cluster = require('cluster');
var http = require('http');

if (cluster.isMaster){
	for (var i = 0; i < 3; i++)
		cluster.fork();

	cluster.on('listening', function(worker, address){
		console.log('Worker ' + worker.id +
			' is listening on port: ', address.port);
	});
} else {
	http.createServer(function(req, res){
		console.log('Worker ' + cluster.worker.id + ' Answering\n');
		res.writeHead(200);
		res.end('Hello word from: ' + cluster.worker.id + '\n');
	}).listen(8000);
}
