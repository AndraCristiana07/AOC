

import os, shutil, subprocess, logging, sys, csv, time, datetime
logging.basicConfig(level=logging.DEBUG)

makefiles = f'{os.getcwd()}/makefiles'

logging.info(f'Makefiles available {os.listdir(makefiles)}')




timestamp = time.asctime(datetime.datetime.now(datetime.timezone.utc).timetuple())

stats = []


years = list(filter(lambda x: x.startswith('2') and len(x) == 4, os.listdir()))

logging.info(f'years {years}')

for y in years:
    
    os.chdir(y)

    days = list(filter(lambda x: 'WIP' not in x, filter(os.path.isdir, os.listdir())))
    days.sort(key=lambda x:  int(x[3:]))
    
    for d in days:
        
        os.chdir(d)
        
        files = list(filter(lambda x: x.startswith('p1') or x.startswith('p2'), os.listdir()))

        for f in files:
            logging.debug(f'{y} {d}')
            rest, extension = f.split('.')
            shutil.copy(f'{makefiles}/Makefile{extension}', 'Makefile')
            
            part = rest[1]
            
            start = time.perf_counter()
            p = subprocess.Popen(f'make run-exec{part}', shell=True)
            p.wait()
            end = time.perf_counter()
            stats.append((timestamp, y, d, part, end - start))
            
            if p.returncode != 0:
                sys.exit(p.returncode)
            
            subprocess.Popen('make clean', shell=True).wait()
            
        os.chdir('..')

    os.chdir('..')

with open('stats/data.csv', '+a', newline='') as f:
    writer = csv.writer(f)
    writer.writerows(stats)