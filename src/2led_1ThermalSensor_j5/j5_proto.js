const { Board, Thermometer } = require("johnny-five");
const board = new Board();

board.on("ready", () => {
  const thermometer = new Thermometer({
    controller: "LM35",
    pin: "A1"
  });

  thermometer.on("change", () => {
    const {celsius, fahrenheit} = thermometer;
    console.log("Thermometer");
    console.log("  celsius      : ", celsius);
    console.log("  fahrenheit   : ", fahrenheit);
    console.log("--------------------------------------");
  });
});