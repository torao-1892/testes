var express = require('express');
var app = express();

app.get('/', function(req, res) {
    var sum = parseInt(req.query.a) + parseInt(req.query.b);
    res.send('ok, the result is: ' + sum);
});

app.get('/vezes', function(req, res) {
    var sum = parseInt(req.query.a) * parseInt(req.query.b);
    res.send('ok, the result is: ' + sum);
});

app.get('/nome', function(req, res) {
    var jsonreturn = {
        nome: req.query.nome,
    sobrenome: req.query.sobrenome
    };
    //res.send(jsonreturn);
    res.send(req.query);
    });
app.listen(3000);
