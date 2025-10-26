# SINGLETON PATTERN

## How to run
### Change mod for script
```bash
chmod +x build.sh clean.sh
```

### Comiple code 
```bash
./build.sh
```

### Clean
```bash
./clean.sh
```

### Note 
- Use static object
```bash
static Database* getInstance(string name)
{
    static Database mInstance(name);
    return &mInstance;
}
```
static mInstance is atomic (thread-safe c++11) without mutex