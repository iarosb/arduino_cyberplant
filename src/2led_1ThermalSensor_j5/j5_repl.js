// arduino UNO
// two leds (red, green)
// firmata standard uploaded to the board

const five = require("johnny-five");
const board = new five.Board({
  repl:true
});

const danger_PIN = 6;
const normal_PIN = 4;

board.on("connect", ()=> {
  console.log("Connected");
});

board.on("ready", () => {

    console.log('Ready');
  const thermometer = new five.Thermometer({
    controller: "LM35",
    pin: "A1",
    freq: 10000
  });

  const danger_LED = new five.Led(danger_PIN);
  const normal_LED = new five.Led(normal_PIN);

  board.repl.inject({
    danger_LED: danger_LED,
    normal_LED: normal_LED,
  });

  thermometer.on("change", () => {
    const {
      celsius,
      fahrenheit
    } = thermometer;

    logTemperature(celsius, fahrenheit);
    signalOnTemp(celsius);
  });

// TODO: refactor util functions
// separate files(modules) where j5 is used only here to handle hardware
  function signalOnTemp(c) {
    if (isTempSafe(c))
    {
      normal_LED.on();
      board.wait(9000, () => {
      normal_LED.off();
     })
    }
    else
    {
      danger_LED.on();
      board.wait(9000, () => {
      danger_LED.off();
     })
    }
   };
   
   function isTempSafe(temp) {
     if (temp < 13.0 || temp > 25.0) {
        return false;
     } else {
        return true;
     }
   };
   
   function logTemperature(c, f) {
     console.log("Celsius: ", c);
     console.log("Farhenheit: ", f);
     console.log("----------------------------");
   };

   board.on("exit", ()=> {
    normal_LED.off();
    danger_LED.off();
  });

});

board.on("close", ()=> {
  console.log("Error: board was disconnected");
});