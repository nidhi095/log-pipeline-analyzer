

# Log Pipeline & Analyzer

## **Project Overview**

The **Log Pipeline & Analyzer** is a lightweight Unix-based system implemented in C that demonstrates a real-time data pipeline for processing log files. This project simulates **production log monitoring** and provides a foundation for learning **inter-process communication (IPC), signals, and file handling** in Unix systems.

---

## **Features**

* **Producer:** Continuously reads new log entries from a log file (`logs/sample.log`).
* **Processor:** Filters log lines containing `ERROR` and passes them along the pipeline.
* **Consumer:** Counts and displays the number of `ERROR` logs in real-time.
* **Lightweight Data Pipeline:** Uses Unix pipes for inter-process communication.
* **Real-time Monitoring:** Works continuously, processing new logs as they are appended.
* **Signals Handling:** Can be extended to handle signals for graceful termination or statistics dumping.

---

## **Tech Stack**

* **Language:** C
* **Platform:** Unix / Linux (tested on WSL Ubuntu)
* **IPC:** Pipes
* **File Handling:** `fopen`, `fgets`
* **Process Management:** `fork()`, `wait()`

---

## **Project Structure**

```
log_pipeline/
├── bin/                 # Compiled binaries
├── logs/                # Sample log files
├── src/                 # Source code files
│   ├── main.c
│   ├── producer.c
│   ├── processor.c
│   ├── consumer.c
│   ├── utils.c
│   └── utils.h
├── Makefile
└── README.md
```

---

## **Setup & Run**

1. Clone the repository:

```bash
git clone <your-repo-url>
cd log_pipeline
```

2. Build the project:

```bash
make
```

3. Run the pipeline:

```bash
./bin/log_pipeline
```

4. Open another terminal to append logs:

```bash
echo "ERROR: Disk failure" >> logs/sample.log
echo "INFO: Startup complete" >> logs/sample.log
```

* Only `ERROR` logs are processed and displayed in real-time.

---

## **Sample Output**

```
[Consumer] ERROR: ERROR: Disk failure | Total ERRORs: 1
[Consumer] ERROR: ERROR: Memory leak | Total ERRORs: 2
```

---

## **Future Enhancements**

* Auto-generate logs to simulate production environments.
* Add **summary reporting** every N logs or on timer.
* Implement **signal-based statistics dumping** (SIGUSR1).
* Integrate a Python AI/ML script for **anomaly detection** in logs.
* Extend the pipeline with **job control (fg/bg)** for process management.

---

## **Learning Outcomes**

* Hands-on experience with **Unix process creation** (`fork()`) and **pipes**.
* Practice with **real-time file monitoring** and log parsing.
* Understanding **producer-consumer pipelines** and **inter-process communication**.
* Preparing for **system-level programming projects** in real-world scenarios.

---

