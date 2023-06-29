#include <TaskScheduler.h>

// We declare the function that we are going to use
void led_blink();

// We create the Scheduler that will be in charge of managing the tasks
Scheduler runner;

// We create the task indicating that it runs every 500 milliseconds, forever, and call the led_blink function
Task TareaLED(500, TASK_FOREVER, &led_blink);

bool statusLED = false;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  // We configure the internal led pin as output
  pinMode(LED_BUILTIN, OUTPUT);

  // We add the task to the task scheduler
  runner.addTask(TareaLED);

  // We activate the task
  TareaLED.enable();
}

// the loop function runs over and over again forever
void loop() {
  // It is necessary to run the runner on each loop
  runner.execute();
}

void led_blink() {
  statusLED = !statusLED;
  digitalWrite(LED_BUILTIN, statusLED);
  Serial.println((String)millis() + " - Led: " + (String)statusLED);
}