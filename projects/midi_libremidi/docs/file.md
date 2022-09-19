# MIDI file I/O usage

## Reading a .mid file

See `midifile_dump.cpp` for a more complete example.

```C++
// Read raw from a MIDI file
std::ifstream file{"path/to/a.mid", std::ios::binary};

std::vector<uint8_t> bytes;
bytes.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

// Initialize our reader object
libremidi::reader r;

// Parse
libremidi::reader::parse_result result = r.parse(bytes);

// If parsing succeeded, use the parsed data
if(result != libremidi::reader::invalid) {
  for(auto& track : r.tracks) {
    for(auto& event : t.events) {
      std::cout << (int) event.m.bytes[0] << '\n';
    }
  }
}
```

## Writing a .mid file

```C++
// Initialize a writer object
libremidi::writer writer;

// Create tracks and events declaratively by changing the track vector directly:
writer.tracks.push_back(
  libremidi::midi_track{
    libremidi::track_event{0, 0, libremidi::message::note_on(1, 45, 35)},
    libremidi::track_event{140, 0, libremidi::message::note_off(1, 45, 0)},
  }
);

// Or through a builder API:
{
  int tick = 500;
  int track = 3;
  libremidi::message msg = libremidi::message::note_on(1, 45, 35);

  // Tracks will be added as needed within safe limits
  writer.add_event(tick, track, msg);
}

// Read raw from a MIDI file
std::ofstream output{"output.mid", std::ios::binary};
writer.write(output);
```
