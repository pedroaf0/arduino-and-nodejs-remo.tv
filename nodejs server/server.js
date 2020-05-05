const express = require('express');
const path = require('path');
const ejs = require('ejs');
const SerialPort = require('serialport')


const app = express();
const server = require('http').createServer(app);
const io = require('socket.io')(server);

app.use(express.static(path.join(__dirname, 'public')));
app.set('views', path.join(__dirname, 'public'));
app.engine('html', ejs.renderFile);
app.set('view engine', 'html');


app.use('/live', (req,res) =>{
    res.render('live.html');
});

const port = new SerialPort('COM12', { baudRate: 9600 })
var namebd = {};
io.on('connection', socket => {
    console.log(`Socket conectado: ${socket.id}`);
    socket.on('cli', data =>{
        console.log(`Comando recebido: ${data} from ${namebd[socket.id]}`);
        socket.broadcast.emit('data', `  ${namebd[socket.id]} clicou em: ${data}`);

        port.write(data);
    })
    socket.on('name', data =>{
        namebd[socket.id] = data;
        socket.broadcast.emit('data', `${data} entrou`);
    })

});



server.listen(3000);