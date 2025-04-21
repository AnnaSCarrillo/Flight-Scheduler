# Flight Scheduler

A C++ project designed to help schedule and prioritize tasks at the airport gate and ticket counter based on flight arrivals and departures.

## Features

- Parses flight schedule data (arrivals and departures)
- Calculates time blocks for required tasks
- Prioritizes tasks based on defined rules:
  - Priority 1: Arrival duties (must be on time)
  - Priority 2: Gate boarding duties (45 minutes before departure)
  - Priority 3: Ticket counter check-ins (2 hours to 45 minutes before departure)
  - Priority 4: Free time

## Built With

- Language: C++
- IDE: Visual Studio Code
- Version Control: Git / GitHub

## Planned Features

- Automatic adjustment of time blocks based on overlapping responsibilities
- Linking of arrivals to their corresponding departures ("turns")
- Visual representation of the final schedule
- Future conversion to a mobile app for on-the-job use

## Project Status

Currently in development. Initial planning and scheduling logic have been outlined.

## Author

Anna Carrillo  
[GitHub Profile](https://github.com/AnnaSCarrillo)
