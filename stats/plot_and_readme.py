
import csv, numpy as np

rows = []
with open('stats/data.csv', 'r', newline='') as f:
    reader = csv.reader(f)
    for line in reader:
        rows.append(line)


output = ''

avg = {}

for year in range(2015, 2024).__reversed__():
    stars = []
    for day in range(1, 25+1):
        p1 = list(filter(lambda x: x[1] == str(year) and x[2] == f'day{day}' and x[3] == '1', rows))
        p2 = list(filter(lambda x: x[1] == str(year) and x[2] == f'day{day}' and x[3] == '2', rows))
        
        done = (
            p1.__len__() != 0,
            p2.__len__() != 0
        )
        
        if done[0] or done[1]:
            if avg.get(year) == None:
                avg[year] = {}

        
        if done[0] and done[1]:
            avg[year][day] = {
                1: sum([float(x[4]) for x in p1]) / len(p1),
                2: sum([float(x[4]) for x in p2]) / len(p2),
            }
            stars.append('<img src="stats/svg/gold_star.svg">')
        elif done[0]:
            avg[year][day] = {
                1: sum([float(x[4]) for x in p1]) / len(p1)
            }
            stars.append('<img src="stats/svg/silver_star.svg">')
        else:
            stars.append('<img src="stats/svg/outline_star.svg">')
        
    output += f'''
### {year}
{''.join(stars)}
<details>
  <summary>Stats</summary>
  <img title="a title" alt="Nothing To See Here" src="stats/year_{year}_plot.png">
</details>
'''

with open('README.md', 'w') as readme:
    readme.write(output)
    
    
    
    
    
    
    
    
    











import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Sample nested dictionary (replace this with your actual data)
data = avg

# Flatten the dictionary into a DataFrame
rows = []
for year, days in data.items():
    for day, parts in days.items():
        for part, value in parts.items():
            rows.append({"Year": year, "Day": day, "Part": part, "Value": value})

df = pd.DataFrame(rows)

# Generate all possible combinations of year, day, and part
years = df['Year'].unique()
all_days = range(1, 26)  # Assuming days 1 through 25
all_parts = [1, 2]

# Create a DataFrame with all combinations to ensure completeness
all_combinations = pd.MultiIndex.from_product([years, all_days, all_parts], names=["Year", "Day", "Part"]).to_frame(index=False)
df_complete = pd.merge(all_combinations, df, on=["Year", "Day", "Part"], how="left")

# Fill NaN values with a placeholder (e.g., 0 or NaN)
df_complete['Value'] = df_complete['Value'].fillna(0)  # Change to np.nan if you want gaps instead of zeroes

# Pivot the DataFrame to get each part as a separate column for side-by-side bars
df_pivot = df_complete.pivot(index=["Year", "Day"], columns="Part", values="Value").reset_index()

# Plot each year separately and save each as a file
for year in df_pivot['Year'].unique():
    df_year = df_pivot[df_pivot['Year'] == year]

    # Set up the plot for the current year
    fig, ax = plt.subplots(figsize=(10, 6))

    # Define x-axis positions and bar width
    x = range(len(df_year))
    width = 0.4

    # Plot Part 1 and Part 2 side-by-side for the current year
    ax.bar([pos - width / 2 for pos in x], df_year[1], width=width, label='Part 1', color='red')
    ax.bar([pos + width / 2 for pos in x], df_year[2], width=width, label='Part 2', color='green')

    # Set labels and title for the plot
    ax.set_xlabel("Day")
    ax.set_ylabel("Execution Time (s)")
    ax.set_title(f"Per day execution time ({year})")

    # Set x-axis labels as the days
    ax.set_xticks(x)
    ax.set_xticklabels(df_year['Day'], rotation=45)

    # Adding legend
    ax.legend(title="Part")

    # Save the plot as a file
    plt.tight_layout()
    filename = f"./stats/year_{year}_plot.png"
    plt.savefig(filename)
    plt.close(fig)  # Close the figure to free up memory

    print(f"Saved plot for year {year} as '{filename}'")
