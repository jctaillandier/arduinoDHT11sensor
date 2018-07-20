//import serial port js package
const SerialPort = require('serialport');

//opening a port
var myPort = new SerialPort('/dev/ttyS3', {
  baudRate: 9600,
  parser: SerialPort.parsers.raw
});

myPort.open();
//how to pass the readline 
    const Readline = SerialPort.parsers.Readline;
    const parser = new Readline({ delimiter: "\r\n" });
    const parsedStream = myPort.pipe(parser);

    myPort.on("open", onPortOpen);
    parsedStream.on("data" , onData);
    myPort.on("close" , onClose);
    myPort.on("error" , onError);

function onPortOpen(){
    console.log("Port open");
}

function onData(data){
    console.log(data);

    console.log("data transfer completed..");
}
function onError(){
    console.log("Error. something went wrong..")
}
function onClose(){
    console.log("Port is closed. Communication terminated");
}